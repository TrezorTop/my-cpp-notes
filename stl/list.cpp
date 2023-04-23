#include <iostream>
#include <list>
#include <string>

using std::cout, std::string;

template <typename T> void printList(std::list<T> list) {
  for (std::list<int>::iterator iterator = list.begin(), end = list.end();
       iterator != end; ++iterator) {
    cout << *iterator;
  }
}

int main() {
  std::list<int> list = {2, 1, 1, 3, 1};

  list.sort();
  list.unique();
  list.reverse();

  //    printList(list);

  for (int &item : list) {
    cout << item << '\n';
  }

  return 0;
}
