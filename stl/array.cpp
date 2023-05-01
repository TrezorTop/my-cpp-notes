#include <array>
#include <iostream>

int main() {
  std::array<int, 5> array{1, 2, 3, 4, 5};

  array.fill(5);

  std::cout << &array.front() << '\n' << '\n';

  for (auto item : array) {
    std::cout << item << '\n';
  }
}
