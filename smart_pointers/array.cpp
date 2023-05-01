#include <iostream>
#include <memory>
#include <string>

using std::cout, std::string;

int main() {
  int SIZE = 5;
  std::shared_ptr<int[]> ptr(new int[SIZE]{1, 6, 2, 7, 4});

  for (int i = 0; i < SIZE; ++i) {
    cout << ptr[i] << '\n';
  }

  return 0;
}
