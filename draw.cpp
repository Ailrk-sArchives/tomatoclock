#include "draw.h"
#include <cstring>
#include <tuple>

namespace tomatoclock {

std::pair<uint32_t, uint32_t> font_geometry(const font_t &font) {
  uint32_t max_width = 0;
  for (int i = 0; i < FONT_HEIGTH; ++i) {
    uint32_t sz = std::strlen(font[i]);
    if (sz > max_width) {
      max_width = sz;
    }
  }
  return {max_width, FONT_HEIGTH};
}

void print_font(font_t font, uint32_t x, uint32_t y) {
  auto x_init = x;
  auto *cell = tb_cell_buffer();
  for (auto &line : font) {
    std::string_view view{line};
    for (auto c : view) {
      tb_put_cell(x, y, cell);
      x++;
    }
    x = x_init;
    y++;
  }
}

void print_clock(uint32_t sec) {
  uint32_t box_width = tb_width();
  uint32_t box_height = tb_height();

  clear();
}

void error(std::string_view message) { std::cerr << message << std::endl; }

void clear() { tb_set_clear_attributes(TB_DEFAULT, TB_DEFAULT); }

} // namespace tomatoclock

#ifdef TEST_DRAW
using namespace tomatoclock;
int main() {
  {
    tb_init();
    print_font(fonts_style1[0], 0, 0);
  }
}
#endif
