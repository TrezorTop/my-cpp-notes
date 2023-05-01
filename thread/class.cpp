#include <iostream>
#include <thread>

class Class {
  public:
    int Sum(int a, int b) {
      std::cout << "thread id: " << std::this_thread::get_id() << " calculating " << a << " + " << b << '\n';

      std::this_thread::sleep_for(std::chrono::milliseconds(3000));

      std::cout << "thread id: " << std::this_thread::get_id() << " calculating is done!" << '\n';

      return a + b;
    }
};

int main() {
  Class aClass;

  std::thread thread(&Class::Sum, &aClass, 12, 34);

  for (int i = 0; i < 5; ++i) {
    std::cout << "thread id: " << std::this_thread::get_id() << " working in main" << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }

  thread.join();

  return 0;
}