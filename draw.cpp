#include "draw.h"
#include <cstring>
#include <tuple>

namespace tomatoclock {

template <int Height>
std::pair<uint32_t, uint32_t>
font_geometry(std::array<const char *, Height> font_array) {
  uint32_t max_width = 0;
  for (int i = 0; i < Height; ++i) {
    if (std::strlen(font_array[i]) > max_width) {
      max_width = font_array[i];
    }
  }
  return {max_width, Height};
}

void print_clock(uint32_t sec) {
  uint32_t box_width = tb_width();
  uint32_t box_height = tb_height();
}

void error(std::string_view message) { std::cerr << message << std::endl; }

void clear() { tb_set_clear_attributes(TB_DEFAULT, TB_DEFAULT); }

} // namespace tomatoclock

#ifdef TEST_DRAW
int main() { std::cout << "draw" << std::endl; }
#endif
