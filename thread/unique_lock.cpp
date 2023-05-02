#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex;

void drawSquare(char character) {
  std::unique_lock<std::mutex> uniqueLock(mutex, std::defer_lock);

  std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  uniqueLock.lock();

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 12; ++j) {
      std::cout << character;
      std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    std::cout << '\n';
  }
  std::cout << '\n';

  uniqueLock.unlock();

  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main() {
  std::thread thread(drawSquare, '#');
  std::thread secondThread(drawSquare, '%');

  thread.join();
  secondThread.join();

  return 0;
}
