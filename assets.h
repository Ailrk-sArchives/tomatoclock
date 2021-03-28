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
#include <array>
#include <string>
#include <string_view>

constexpr std::string_view title = "ｔｏｍａｔｏｃｌｏｃｋ";

enum class RUNE { F0 = 0, F1, F2, F3, F4, F5, F6, F7, F8, F9, COLOMN };

#define RUNE_HEIGTH 6
#define RUNE_KIND 11
using rune_t = std::array<const char *, RUNE_HEIGTH>;
using rune_table = std::array<rune_t, RUNE_KIND>;

inline int
ix(char n) {
    if (std::isdigit(n)) {
        return n - '0';
    }
    if (n == ':') {
        return RUNE_KIND - 1;
    }
    return n;
}

constexpr rune_table runes_style1{ {
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
} };

constexpr rune_table runes_style2{ {
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
} };

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
