#pragma once

#include <iostream>
#include <optional>
#include <sstream>
#include <string>

namespace tomatoclock {

enum class precision_t { SEC = 0, MIN, HOUR };

const char *show(precision_t);
uint32_t to_s(precision_t);
std::optional<std::string> format_time(uint32_t sec, precision_t upper,
                                       precision_t lower);

} // namespace tomatoclock
