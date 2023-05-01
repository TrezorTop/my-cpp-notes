#include <iostream>
#include <vector>

#include "Person/Person.h"

int main() {
  std::vector<Person> persons = {
      Person("name 1", 25),
      Person("name 2", 17),
      Person("name 3", 19),
      Person("name 4", 28),
  };

  std::sort(persons.begin(), persons.end(), [](const Person& current, const Person& prev) -> bool {
    return current.age < prev.age;
  });

  for (const Person& person : persons) {
    std::cout << person.name << ' ' << person.age << '\n';
  }

  return 0;
}
