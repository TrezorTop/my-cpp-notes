#include <chrono>
#include <iostream>
#include <string>
#include <thread>

void sum(int a, int b, int &result) {
  std::cout << "Thread ID: " << std::this_thread::get_id() << ", calculating "
            << a << " + " << b << '\n';

  std::this_thread::sleep_for(std::chrono::milliseconds(3000));

  std::cout << "calculating is done!" << '\n';

  result = a + b;
}

int main() {
  std::cout << "main start" << '\n';

  int result;

  std::thread thread(sum, 5, 2, std::ref(result));

  for (int i = 0; i < 6; ++i) {
    std::cout << "Thread ID: " << std::this_thread::get_id() << ", main"
              << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  thread.join();

  std::cout << result << '\n';

  std::cout << "main end" << '\n';
  return 0;
}
