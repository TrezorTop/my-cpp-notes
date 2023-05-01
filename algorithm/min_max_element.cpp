#include <iostream>
#include <list>
#include <vector>

#include "Person/Person.h"

void baseExample() {
  std::vector<Person> persons = {
      Person("name 1", 32),
      Person("name 1", 15),
      Person("name 2", 23),
      Person("name 3", 15),
      Person("name 4", 31),
      Person("name 5", 38),
  };

  auto max = std::max_element(persons.begin(), persons.end(), [](const Person& current, const Person& prev) -> bool {
    return current.age < prev.age;
  });
  auto min = std::min_element(persons.begin(), persons.end(), [](const Person& current, const Person& prev) -> bool {
    return current.age < prev.age;
  });

  std::cout << "Max: " << max->age << '\n';
  std::cout << "Min: " << min->age << '\n';
}

int main() {
  std::vector<Person> persons = {
      Person("name 1", 32),
      Person("name 1", 15),
      Person("name 2", 23),
      Person("name 3", 15),
      Person("name 4", 31),
      Person("name 5", 38),
  };

  auto result =
      std::minmax_element(persons.begin(), persons.end(), [](const Person& current, const Person& prev) -> bool {
        return current.age < prev.age;
      });

  std::cout << "Min: " << result.first->age << " Max: " << result.second->age << '\n';

  return 0;
}
