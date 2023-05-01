#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex;
std::recursive_mutex recursiveMutex;

void Foo(int a) {
  recursiveMutex.lock();
  if (a <= 0) {
    recursiveMutex.unlock();
    std::cout << '\n';
    return;
  };

  std::cout << a << ' ';
  std::this_thread::sleep_for(std::chrono::milliseconds(250));
  Foo(--a);
  recursiveMutex.unlock();
}

int main() {
  std::thread thread(Foo, 10);
  std::thread secondThread(Foo, 10);

  thread.join();
  secondThread.join();

  return 0;
}