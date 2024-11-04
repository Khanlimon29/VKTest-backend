#include "Tasks.h"
#include "Time.h"
#include <iostream>

void task1() {
	std::cout << getCurrentTime() << " | First task is running on threadID " << std::this_thread::get_id() << "\n";
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << getCurrentTime() << " | First task is completed\n";
}

void task2() {
	std::cout << getCurrentTime() << " | Second task is running on threadID " << std::this_thread::get_id() << "\n";
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << getCurrentTime() << " | Second task is completed\n";
}

void task3() {
	std::cout << getCurrentTime() << " | Third task is running on threadID " << std::this_thread::get_id() << "\n";
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << getCurrentTime() << " | Third task is completed\n";
}

void task4() {
	std::cout << getCurrentTime() << " | Fourth task is running on threadID " << std::this_thread::get_id() << "\n";
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << getCurrentTime() << " | Fourth task is completed\n";
}

void task5() {
	std::cout << getCurrentTime() << " | Fifth task is running on threadID " << std::this_thread::get_id() << "\n";
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << getCurrentTime() << " | Fifth task is completed\n";
}