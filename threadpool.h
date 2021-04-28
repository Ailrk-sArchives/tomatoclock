#include <condition_variable>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

namespace tomatoclock {
class thread_pool {
    std::vector<std::thread> workers;
    std::mutex queue_mutex;
    std::condition_variable cv;
};

} // namespace tomatoclock
