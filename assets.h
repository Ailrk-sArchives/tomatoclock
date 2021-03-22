#pragma once
#include <array>
#include <string>
#include <string_view>

constexpr std::string_view title = "ｔｏｍａｔｏｃｌｏｃｋ";

enum class RUNE { F0 = 0, F1, F2, F3, F4, F5, F6, F7, F8, F9, COLOMN };

#define RUNE_HEIGTH 6
#define RUNE_KIND 11
using rune_t = std::array<const char *, RUNE_HEIGTH>;
using rune_table = std::array<rune_t, RUNE_KIND>;

inline int ix(char n) {
  if (std::isdigit(n)) {
    return n - '0';
  }
  if (n == ':') {
    return RUNE_KIND - 1;
  }
  return n;
}

constexpr rune_table runes_style1{{
    {
        "███████",
        "██   ██",
        "██   ██",
        "██   ██",
        "███████",
        "       ",
    },

    {
        "██",
        "██",
        "██",
        "██",
        "██",
        "  ",
    },

    {
        "███████",
        "     ██",
        "███████",
        "██     ",
        "███████",
        "       ",
    },

    {
        "███████",
        "     ██",
        "███████",
        "     ██",
        "███████",
        "       ",

    },

    {
        "██   ██",
        "██   ██",
        "███████",
        "     ██",
        "     ██",
        "       ",

    },

    {
        "███████",
        "██     ",
        "███████",
        "     ██",
        "███████",
        "       ",
    },

    {
        "███████",
        "██     ",
        "███████",
        "██   ██",
        "███████",
        "       ",
    },

    {
        "███████",
        "     ██",
        "     ██",
        "     ██",
        "     ██",
        "       ",
    },

    {
        "███████",
        "██   ██",
        "███████",
        "██   ██",
        "███████",
        "       ",
    },

    {
        "███████",
        "██   ██",
        "███████",
        "     ██",
        "███████",
        "       ",

    },

    {
        "  ",
        "██",
        "  ",
        "██",
        "  ",
        "  ",
    },
}};

constexpr rune_table runes_style2{{
    {
        " ██████╗ ",
        "██╔═████╗",
        "██║██╔██║",
        "████╔╝██║",
        "╚██████╔╝"
        " ╚═════╝ ",
    },

    {
        " ██╗",
        "███║",
        "╚██║",
        " ██║",
        " ██║",
        " ╚═╝",
    },

    {
        "██████╗ ",
        "╚════██╗",
        " █████╔╝",
        "██╔═══╝ ",
        "███████╗",
        "╚══════╝",
    },

    {
        "██████╗ ",
        "╚════██╗",
        " █████╔╝",
        " ╚═══██╗",
        "██████╔╝",
        "╚═════╝ ",
    },

    {
        "██╗  ██╗",
        "██║  ██║",
        "███████║",
        "╚════██║",
        "     ██║",
        "     ╚═╝",
    },

    {
        "███████╗",
        "██╔════╝",
        "███████╗",
        "╚════██║",
        "███████║",
        "╚══════╝",
    },

    {
        " ██████╗ ",
        "██╔════╝ ",
        "███████╗ ",
        "██╔═══██╗",
        "╚██████╔╝",
        " ╚═════╝ ",
    },

    {
        "███████╗",
        "╚════██║",
        "    ██╔╝",
        "   ██╔╝ ",
        "   ██║  ",
        "   ╚═╝  ",
    },

    {
        " █████╗ ",
        "██╔══██╗",
        "╚█████╔╝",
        "██╔══██╗",
        "╚█████╔╝",
        " ╚════╝ ",
    },

    {
        " █████╗ ",
        "██╔══██╗",
        "╚██████║",
        " ╚═══██║",
        " █████╔╝",
        " ╚════╝ ",
    },

    {
        "   ",
        "██╗",
        "╚═╝",
        "██╗",
        "╚═╝",
        "   ",
    },
}};

constexpr const char *help_info = R"(
  usage: coutdown [OPTIONS]

  args:
    -m <timeformat>             countdown by minutes, format mm:ss
    -h <timeformat>             countdown by hour, format hh:mm:ss or hh:mm
    -c <script>                 the shell script to run when the count is finished
    -s <scriptfile>             shell script file
    -h                          print this message
    -t                          display tui
    -l                          list current status
    -t <text>                   extra message to show on the tui.
    -r                          show history
)";
