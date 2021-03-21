#include "draw.h"
#include <cstring>
#include <functional>
#include <tuple>

namespace tomatoclock {

back_buffer::back_buffer(uint32_t w, uint32_t h) {
  int t = tb_init();
  if (t == -1) {
    tb_shutdown();
    fprintf(stderr, "error happended when initializing termbox");
    abort();
  }
  bbw = w;
  bbh = h;
  buffer = static_cast<struct tb_cell *>(calloc(sizeof(struct tb_cell), w * h));
}

back_buffer::back_buffer() {
  uint32_t w = tb_width();
  uint32_t h = tb_height();
  back_buffer(w, h);
}

back_buffer::~back_buffer() { free(buffer); }

void back_buffer::realloc(uint32_t w, uint32_t h) {
  if (buffer) {
    free(buffer);
  }
  bbw = w;
  bbh = h;
  buffer = static_cast<struct tb_cell *>(calloc(sizeof(struct tb_cell), w * h));
}

void back_buffer::update(uint32_t x, uint32_t y, void (*draw)(back_buffer &)) {
  tb_clear();

  if (x != -1 && y != -1) {
  }
  memcpy(tb_cell_buffer(), buffer, sizeof(struct tb_cell) * bbh * bbw);
  tb_present();
}
void back_buffer::update(void (*draw)(back_buffer &)) {
  tb_clear();

  memcpy(tb_cell_buffer(), buffer, sizeof(struct tb_cell) * bbh * bbw);

  draw(*this);
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

void print_rune(back_buffer &buf, rune_t rune, uint32_t x, uint32_t y) {
  auto x_init = x;
  for (auto &line : rune) {
    std::string_view view{line};
    for (auto c : view) {
      tb_change_cell(x, y, c, TB_DEFAULT, TB_DEFAULT);
      x++;
    }
    x = x_init;
    y++;
  }
}

void print_clock(back_buffer &buf, uint32_t sec) {
  uint32_t box_width = tb_width();
  uint32_t box_height = tb_height();
}

void error(std::string_view message) { std::cerr << message << std::endl; }

} // namespace tomatoclock

#ifdef TEST_DRAW
using namespace tomatoclock;
static back_buffer buff;
int main() {
  uint32_t w = tb_width();
  uint32_t h = tb_height();
#define TEST_SINGLE_RUNE
#ifdef TEST_SINGLE_RUNE
  {
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
      }

      buff.update([](back_buffer &buffer) {
        print_rune(buffer, runes_style1[0], 0, 0);
      });
    }
  }
#endif
  tb_shutdown();
  return 0;
}
#endif
