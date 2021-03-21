#pragma once
#include "assets.h"
#include "time.h"
#include <iostream>
#include <memory>
#include <termbox.h>

namespace tomatoclock {
void realloc_buffer(uint32_t, uint32_t);
void error();

// simple wrapper, only intended to manage the lifetime of tb_cel
struct back_buffer {
  struct tb_cell *buffer;
  uint32_t bbh = 0;
  uint32_t bbw = 0;

  back_buffer(uint32_t w, uint32_t h);
  back_buffer();
  ~back_buffer();
  void realloc(uint32_t w, uint32_t h);
  void update(uint32_t x, uint32_t y, void (*)(back_buffer &));
  void update(void (*)(back_buffer &));
};

void print_rune(back_buffer &buf, rune_t rune, uint32_t x, uint32_t y);
void print_clock(back_buffer &buf, uint32_t sec);
} // namespace tomatoclock
