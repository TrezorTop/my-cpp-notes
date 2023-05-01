#include <iostream>
#include <vector>

#include "Person/Person.h"

int main() {
  std::vector<Person> persons = {
      Person("name 1", 32),
      Person("name 1", 15),
      Person("name 2", 23),
      Person("name 3", 15),
      Person("name 4", 31),
      Person("name 5", 38),
  };

  persons.erase(
      std::remove_if(persons.begin(), persons.end(), [](const Person& person) -> bool { return person.age < 20; }),
      persons.end()
  );

  for (const auto& item : persons) {
    std::cout << item.name << ' ' << item.age << '\n';
  }
}
