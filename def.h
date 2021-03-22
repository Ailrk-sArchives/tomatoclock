#pragma once
#include "assets.h"
#include "time.h"
#include <vector>

namespace tomatoclock {

enum class precision_t { SEC = 0, MIN, HOUR };

struct timefmt_t {
  precision_t upper;
  precision_t lower;
};

struct config_t {
  // contorl display
  bool use_history;
  bool use_tui;
  bool use_gui;
  bool show_list;

  // cmd options
  bool show_help;

  // style setting
  timefmt_t timefmt;
  std::string fmt_str;
  rune_table &style;
};

} // namespace tomatoclock
