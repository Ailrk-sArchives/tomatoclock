#pragma once

#include "def.h"
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

namespace tomatoclock {

enum class precision_t { SEC = 0, MIN, HOUR };

inline bool operator>(precision_t x, precision_t y) {
  return static_cast<uint32_t>(x) > static_cast<uint32_t>(y);
}

inline bool operator<(precision_t x, precision_t y) {
  return static_cast<uint32_t>(x) < static_cast<uint32_t>(y);
}

const char *show(precision_t);
uint32_t to_s(precision_t);
std::optional<std::string> mk_timestr(uint32_t sec, precision_t upper,
                                      precision_t lower);

std::optional<std::tuple<uint32_t, timefmt_t>>
parse_time_str(std::string_view time_str);

} // namespace tomatoclock
