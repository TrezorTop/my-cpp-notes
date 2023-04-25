#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> map;

  map.insert(std::make_pair("zero", 0));
  map.insert(std::pair<std::string, int>("one", 1));
  map.emplace("two", 2);

  auto iterator = map.find("zero");

  if (iterator != map.end())
    std::cout << iterator->first << '\n' << '\n';

  std::cout << map["one"];
}
