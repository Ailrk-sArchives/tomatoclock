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

#include "def.h"
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

namespace tomatoclock {

inline bool
operator>(precision_t x, precision_t y) {
    return static_cast<uint32_t>(x) > static_cast<uint32_t>(y);
}

inline bool
operator<(precision_t x, precision_t y) {
    return static_cast<uint32_t>(x) < static_cast<uint32_t>(y);
}

const char *show(precision_t);
uint32_t to_s(precision_t);
std::optional<std::string>
mk_timestr(uint32_t sec, precision_t upper, precision_t lower);

std::optional<std::tuple<uint32_t, timefmt_t>>
parse_time_str(std::string_view time_str);

} // namespace tomatoclock
