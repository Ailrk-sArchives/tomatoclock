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
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

// it's essentially an event loop with only timout event.

namespace tomatoclock {

class tomato_event {

  public:
    size_t event_id;
    using key_type = void;
    using comparator = void;
    virtual ~tomato_event() {}
    virtual decltype(event_id) get_event_id() = 0;
    virtual void activate() = 0;
};

template <typename Context>
class tomato_task_event : public tomato_event {
  public:
    using task_t = std::function<std::thread(Context)>;
};

template <>
class tomato_task_event<void> : public tomato_event { // void case
  public:
    using task_t = std::function<std::thread()>;
};

///! tasks with their duration in ms. the duration will be updated in each
///! loop.
class tomato_timer_event : public tomato_task_event<void> {
    std::string_view sh_script;
    size_t duration_in_ms;

  public:
    ///! comparator for the priority queue.
    ///! The task with 0 duration_in_ms will always be at the top.
    ///! If there are multiple tasks with 0 duration, they will be put into the
    ///! exectution buffer.
    struct timer_event_comparator
        : std::binary_function<tomato_timer_event, tomato_timer_event, bool> {
        bool operator()(const tomato_timer_event &x,
                        const tomato_timer_event &y) const {
            return x.duration_in_ms < y.duration_in_ms;
        }
    };

    using key_type = size_t;
    using comparator = timer_event_comparator;

    ///! active an task.
    ///! essentially it adding the task into the running queue.
    void activate() override;
    decltype(event_id) get_event_id() override;
};

///! event_queue
template <typename T>
class event_queue {
    virtual ~event_queue() {}
    virtual void add(T value) = 0;
    virtual T get() = 0;
};

template <typename T>
using timer_queue =
    std::priority_queue<T, std::vector<T>, tomato_timer_event::comparator>;

// task queue holds the list of tasks and there completion time.
template <typename T>
class tomato_queue : event_queue<T> {
    timer_queue<T> q;

  public:
    tomato_queue()
        : q({}) {}

    void add(T value) {}
    T get() {}
};

} // namespace tomatoclock
