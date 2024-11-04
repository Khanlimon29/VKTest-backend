#include "Tasks.h"
#include "Planner.h"
#include "Time.h"
#include <iostream>

int main() {
	TaskScheduler scheduler;
	std::time_t timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	std::cout << "Start time: " << getCurrentTime() << "\n";
	std::cout << "Adding tasks to scheduler...\n\n";

	scheduler.Add(task4, timestamp + 5);
	scheduler.Add(task5, timestamp + 1);
	scheduler.Add(task3, timestamp + 5);
	scheduler.Add(task1, timestamp + 2);
	scheduler.Add(task2, timestamp + 10);

	return 0;
}