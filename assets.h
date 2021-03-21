#pragma once
#include <array>
#include <string>
#include <string_view>

constexpr std::string_view title = "ｔｏｍａｔｏｃｌｏｃｋ";

enum class FONT { F0 = 0, F1, F2, F3, F4, F5, F6, F7, F8, F9, COLOMN };

#define FONT_HEIGTH 6
#define FONT_KIND 11
using font_t = std::array<const char *, FONT_HEIGTH>;
using font_table = std::array<font_t, FONT_KIND>;

constexpr font_table fonts_style1{{
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

constexpr font_table fonts_style2{{
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
