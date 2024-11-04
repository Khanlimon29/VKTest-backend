#include "Planner.h"
#include <iostream>

TaskScheduler::TaskScheduler(size_t threadCount) : stopFlag(false) {
    for (size_t i = 0; i < threadCount; ++i) {
        threads.emplace_back([this]() { this->worker(); });
    }
}

TaskScheduler::~TaskScheduler() {
    {
        std::unique_lock<std::mutex> lock(mtx);
        stopFlag = true;
    }
    cv.notify_all();
    for (std::thread& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

void TaskScheduler::Add(std::function<void()> task, std::time_t timestamp) {
    {
        std::unique_lock<std::mutex> lock(mtx);
        taskQueue.push(ScheduledTask{ task, timestamp });
    }
    cv.notify_all();
}

void TaskScheduler::worker() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return stopFlag || !taskQueue.empty(); });

        if (stopFlag && taskQueue.empty()) {
            return;
        }

        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

        if (!taskQueue.empty() && taskQueue.top().timestamp <= now) {
            auto task = taskQueue.top().task;
            taskQueue.pop();
            lock.unlock();
            task();
        }
        else if (!taskQueue.empty()) {
            cv.wait_until(lock, std::chrono::system_clock::from_time_t(taskQueue.top().timestamp));
        }
    }
}
