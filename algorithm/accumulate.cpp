#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> numbers = {1, 6, 2, 3, 4};

  auto result = std::accumulate(
      std::next(std::begin(numbers)),
      std::end(numbers),
      std::to_string(numbers[0]),
      [](const std::string& acc, int current) { return acc + '-' + std::to_string(current); }
  );

  std::cout << result << '\n';
}