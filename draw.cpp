#include "draw.h"
#include "def.h"
#include <cstring>
#include <functional>
#include <tuple>
#include <vector>

namespace tomatoclock {

#define TBCELL_SZ (sizeof(struct tb_cell))

back_buffer::back_buffer(uint32_t w, uint32_t h) {
  int t = tb_init();
  if (t == -1) {
    tb_shutdown();
    fprintf(stderr, "error happended when initializing termbox");
    abort();
  }
  bbw = w;
  bbh = h;
  bbuffer =
      static_cast<struct tb_cell *>(calloc(sizeof(struct tb_cell), w * h));
}

back_buffer::back_buffer() {
  uint32_t w = tb_width();
  uint32_t h = tb_height();
  back_buffer(w, h);
}

back_buffer::~back_buffer() { free(bbuffer); }

void back_buffer::realloc(uint32_t w, uint32_t h) {
  if (bbuffer) {
    free(bbuffer);
  }
  bbw = w;
  bbh = h;
  bbuffer = static_cast<struct tb_cell *>(calloc(TBCELL_SZ, w * h));
}

void back_buffer::update(uint32_t x, uint32_t y, void (*draw)()) {
  tb_clear();
  // TODO update position.
  memcpy(tb_cell_buffer(), bbuffer, TBCELL_SZ * bbh * bbw);
  tb_present();
}
void back_buffer::update(void (*draw)()) {
  tb_clear();
  memcpy(tb_cell_buffer(), bbuffer, TBCELL_SZ * bbh * bbw);
  draw();
  tb_present();
}

std::pair<uint32_t, uint32_t> rune_geometry(const rune_t &rune) {
  uint32_t max_width = 0;
  for (int i = 0; i < RUNE_HEIGTH; ++i) {
    uint32_t sz = std::strlen(rune[i]);
    if (sz > max_width) {
      max_width = sz;
    }
  }
  return {max_width, RUNE_HEIGTH};
}

static std::vector<uint32_t> to_utf8(const char *line) {
  std::string_view view{line};
  std::vector<uint32_t> vec(64, 0);
  uint32_t result;
  while (view.size() > 0) {
    uint32_t sz = tb_utf8_char_to_unicode(&result, view.data());
    vec.push_back(result);
    view = view.substr(sz);
  }
  return vec;
}

void print_rune(rune_t rune, uint32_t x, uint32_t y) {
  auto x_init = x;
  for (auto line : rune) {
    std::vector<uint32_t> unicodes{to_utf8(line)};
    for (auto code : unicodes) {
      tb_change_cell(x, y, code, TB_DEFAULT, TB_DEFAULT);
      x++;
    }
    x = x_init;
    y++;
  }
}

void print_clock(rune_table table, const timefmt_t &fmt, uint32_t sec) {
  uint32_t box_width = tb_width();
  uint32_t box_height = tb_height();
  auto timestr_opt = mk_timestr(sec, fmt.upper, fmt.lower);
  if (!timestr_opt.has_value) {
    fprintf(stderr, "error when formatting the time\n");
    abort();
  }

  std::vector<rune_t> runes;
  for (char c : timestr_opt.value()) {
    if (c == ':') {
      runes.push_back(table[RUNE_KIND]);
    } else {
      runes.push_back(table[c - '0']);
    }
  }

  for (auto rune : runes) {
    print_rune(rune, 10, 10);
  }
}

void error(std::string_view message) { std::cerr << message << std::endl; }

} // namespace tomatoclock

#ifdef TEST_DRAW
#include <fstream>
#include <iostream>
using namespace tomatoclock;
static back_buffer buff;

int main() {
  uint32_t w = tb_width();
  uint32_t h = tb_height();
  std::ofstream out("debug.log");
  auto *coutbuf = std::cout.rdbuf();
  std::cout.rdbuf(out.rdbuf());
#define TEST_FORMATED_TIME

#ifdef TEST_SINGLE_RUNE
  auto draw = []() {
    print_rune(runes_style1[0], 0, 0);
    print_rune(runes_style1[1], 20, 10);
    print_rune(runes_style1[2], 60, 20);
  };
#endif

#ifdef TEST_FORMATED_TIME
  auto draw = []() {
    print_clock(runes_style1, timefmt_t{precision_t::MIN, precision_t::SEC},
                1400);
  };
#endif

  {
    buff.update(draw);
    for (;;) {
      struct tb_event ev;
      int t = tb_poll_event(&ev);
      if (t == -1) {
        tb_shutdown();
        fprintf(stderr, "termbox event error");
        return -1;
      }

      switch (t) {
      case TB_EVENT_KEY:
        if (ev.key == TB_KEY_ESC) {
          tb_shutdown();
          return 0;
        }
        break;
      }

      buff.update(draw);
    }
  }
  tb_shutdown();
  return 0;
}
#endif
