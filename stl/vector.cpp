#include <iostream>
#include <string>
#include <vector>

using std::cout, std::string, std::vector;

int main() {
  vector<int> array = {1, 2, 3};

  vector<int>::iterator iterator = array.begin();

  std::advance(iterator, 1);

  array.insert(iterator, 12);

  std::advance(iterator, -1);

  array.erase(iterator, iterator + 2);

  for (vector<int>::iterator i = array.begin(), size = array.end(); i != size; i++) {
    cout << *i << '\n';
  }

  return 0;
}
