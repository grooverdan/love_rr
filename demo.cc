#include <iostream>
#include <thread>
#include <atomic>

// Shared variable
int counter = 0;

// Function that will be executed by threads
void incrementCounter(int interations) {
	for (int i = 0; i < interations; ++i) {
		++counter;
	}
}

int main() {
	const int interations = 10000000;

	// Create threads that run incrementCounter
	std::thread t1(incrementCounter, interations);
	std::thread t2(incrementCounter, interations);
	std::thread t3(incrementCounter, interations);
	std::thread t4(incrementCounter, interations);
	std::thread t5(incrementCounter, interations);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	std::cout << "Final counter value: " << counter;
}
