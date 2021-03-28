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
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

// it's essentially an event loop with only timout event.

namespace tomatoclock {

struct tomato_task {
    std::string_view sh_script;
    size_t duration_in_ms;
};

// run a task
void
run_task(tomato_task task);

// task queue holds the list of tasks and there complition time.
template <typename T>
class tomato_queue {
    std::unique_ptr<std::queue<T>> queue_;

  public:
    tomato_queue()
        : queue_(std::make_unique<std::queue<T>>()) {}

    void add(T value) {}
    T get() {}
};

std::thread
countdown(int sec);
} // namespace tomatoclock
