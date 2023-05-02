#include <iostream>
#include <vector>

int main() {
  std::vector<int> arr = {
      1,
      1,
      1,
      2,
      3,
      4,
      5,
      6,
      6,
      7,
      8,
      9,
      1,
      1,
  };

  auto result = std::unique(std::begin(arr), std::end(arr));

  arr.erase(result, arr.end());

  for (int& item : arr) {
    std::cout << item << '\n';
  }

  return 0;
}