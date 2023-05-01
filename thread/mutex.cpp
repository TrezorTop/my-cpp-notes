#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex;

void drawSquare(char character) {
  mutex.lock();

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 12; ++j) {
      std::cout << character;
      std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    std::cout << '\n';
  }
  std::cout << '\n';

  mutex.unlock();
}

int main() {
  std::thread thread(drawSquare, '#');

  std::thread secondThread(drawSquare, '%');

  thread.join();
  secondThread.join();

  return 0;
}
