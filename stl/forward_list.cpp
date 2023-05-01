#include <forward_list>
#include <iostream>
#include <string>

using std::cout, std::string;

int main() {
  std::forward_list<int> forwardList;

  forwardList.push_front(1);
  forwardList.push_front(2);
  forwardList.push_front(3);

  std::forward_list<int>::iterator iterator = forwardList.begin();

  cout << *++iterator << '\n';
}
