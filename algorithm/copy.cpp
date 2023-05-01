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

  std::vector<Person> result;

  std::copy_if(persons.begin(), persons.end(), std::back_inserter(result), [](const Person& person) -> bool {
    return person.age > 20;
  });

  for (const Person& person : result) {
    std::cout << person.name << ' ' << person.age << '\n';
  }
}
