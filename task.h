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
