#include <iostream>
#include <vector>

#include "Person/Person.h"

int main() {
  std::vector<Person> persons = {
      Person("name 1", 32),
      Person("name 1", 15),
      Person("name 2", 53),
      Person("name 3", 12),
      Person("name 4", 31),
      Person("name 5", 48),
  };

  auto result = std::find_if(persons.begin(), persons.end(), [](const Person& person) -> bool {
    return person.name == "name 2";
  });

  if (result != persons.end()) std::cout << result->name << '\n';

  return 0;
}
