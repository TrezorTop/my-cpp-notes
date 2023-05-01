#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex;

void drawSquare(char character) {
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  {
    std::lock_guard<std::mutex> guard(mutex);

    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 12; ++j) {
        std::cout << character;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }

  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main() {
  std::thread thread(drawSquare, '#');
  std::thread secondsThread(drawSquare, '%');

  thread.join();
  secondsThread.join();

  return 0;
}
