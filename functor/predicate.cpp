#include <algorithm>
#include <iostream>
#include <vector>

class PositiveNumber {
  public:
    PositiveNumber(int number) {
      this->number = number;
    }

    int number;

    bool operator()(const PositiveNumber& number) {
      return number.number > 0;
    }
};

int main() {
  std::vector<PositiveNumber> positiveNumbers = {1, 2, -5, 6, -2};

  int result = std::count_if(positiveNumbers.begin(), positiveNumbers.end(), positiveNumbers.front());

  std::cout << result << '\n';

  return 0;
}