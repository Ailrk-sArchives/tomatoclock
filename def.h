#pragma once
#include "assets.h"
#include "time.h"
#include <vector>

namespace tomatoclock {

struct config_t {
  // contorl display
  bool use_history;
  bool use_tui;
  bool use_gui;
  bool show_list;

  // cmd options
  bool show_help;

  // style setting
  std::string format_str;
  rune_table &rune_style;
};

} // namespace tomatoclock
