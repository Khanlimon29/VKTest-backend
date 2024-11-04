#pragma once
#include <functional>
#include <queue>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <ctime>
#include <vector>

struct ScheduledTask {
    std::function<void()> task;
    std::time_t timestamp;

    bool operator<(const ScheduledTask& other) const {
        return timestamp > other.timestamp;
    }
};

class TaskScheduler {
public:
    TaskScheduler(size_t threadCount = std::thread::hardware_concurrency());
    ~TaskScheduler();

    void Add(std::function<void()> task, std::time_t timestamp);

private:
    std::priority_queue<ScheduledTask> taskQueue;
    std::mutex mtx;
    std::condition_variable cv;
    std::vector<std::thread> threads;
    bool stopFlag;

    void worker();
};