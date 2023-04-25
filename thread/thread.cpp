#include <chrono>
#include <iostream>
#include <string>
#include <thread>

void calculate(int count) {
  for (int i = 0; i < count; ++i) {
    std::cout << "Thread ID: " << std::this_thread::get_id()
              << ", calculating..." << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  std::cout << "calculating is done!" << '\n';
}

int main() {
  std::cout << "main start" << '\n';

  std::thread thread(calculate, 5);

  for (int i = 0; i < 6; ++i) {
    std::cout << "Thread ID: " << std::this_thread::get_id() << ", main"
              << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  thread.join();
  std::cout << "main end" << '\n';
  return 0;
}
