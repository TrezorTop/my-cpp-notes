#include <iostream>
#include <random>
#include <vector>

int main() {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

  // Use a random number generator to shuffle the elements
  std::random_device rd;
  std::mt19937 gen(rd());

  std::shuffle(arr.begin(), arr.end(), gen);

  for (int& item : arr) {
    std::cout << item << '\n';
  }

  return 0;
}