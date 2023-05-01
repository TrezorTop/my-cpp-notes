#include <algorithm>
#include <iostream>

int main() {
  int arr[] = {
      1,
      2,
      3,
      4,
      5,
      6,
  };

  std::for_each(std::begin(arr), std::end(arr), [](int& item) { std::cout << item << '\n'; });

  return 0;
}
