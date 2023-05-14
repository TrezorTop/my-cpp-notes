#include <iostream>
#include <map>
#include <set>
#include <vector>

template <typename T>
void Print(std::ostream& ostream, T& container);

template <typename T>
std::ostream& operator<<(std::ostream& ostream, std::vector<T>& container) {
  ostream << '{';
  Print(ostream, container);
  ostream << '}';

  return ostream;
}

template <typename T>
std::ostream& operator<<(std::ostream& ostream, std::set<T>& container) {
  ostream << '[';
  Print(ostream, container);
  ostream << ']';

  return ostream;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& ostream, std::map<T1, T2>& container) {
  ostream << '<';
  Print(ostream, container);
  ostream << '>';

  return ostream;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& ostream, const std::pair<const T1, T2>& pair) {
  ostream << '(' << pair.first << ", " << pair.second << ')';

  return ostream;
}

template <typename T>
void Print(std::ostream& ostream, T& container) {
  for (const auto& item : container) {
    if (item != *container.begin()) ostream << ", ";
    ostream << item;
  }
}

int main() {
  std::set<std::string> set{"setElement1", "setElement2", "setElement3"};
  std::vector<std::string> vector{"vectorElement1", "vectorElement2", "vectorElement3"};
  std::map<int, std::string> map{{1, "string1"}, {2, "string2"}};

  std::cout << set << '\n';
  std::cout << vector << '\n';
  std::cout << map << '\n';

  return 0;
}