// tomato-clock
// Copyright © 2021 ailrk

// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
// OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#pragma once
#include "assets.h"
#include "time.h"
#include <iostream>
#include <memory>
#include <termbox.h>

namespace tomatoclock {
void realloc_buffer(uint32_t, uint32_t);
void
error();

// simple wrapper, only intended to manage the lifetime of tb_cel
struct back_buffer {
    struct tb_cell *bbuffer;
    uint32_t bbh = 0;
    uint32_t bbw = 0;

    back_buffer(uint32_t w, uint32_t h);
    back_buffer();
    ~back_buffer();
    void realloc(uint32_t w, uint32_t h);
    void update(uint32_t x, uint32_t y, void (*)());
    void update(void (*)());
};

void
print_rune(rune_t rune, uint32_t x, uint32_t y);
void
print_clock(rune_table table, const timefmt_t &fmt, uint32_t sec);
} // namespace tomatoclock
