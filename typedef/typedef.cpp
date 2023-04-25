#include <iostream>
#include <vector>

typedef std::vector<int> int_vector;
typedef std::vector<char> string_vector;

int main() {
  int_vector intVector;
  string_vector stringVector;

  intVector.push_back(1);
  intVector.push_back(2);
  stringVector.push_back('3');

  return 0;
}