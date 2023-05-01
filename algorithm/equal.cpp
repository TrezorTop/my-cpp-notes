#include <algorithm>
#include <iostream>
#include <vector>

#include "Person/Person.h"

void simpleExample() {
  std::vector<int> numbers = {1, 6, 2, 3, 4, 2};
  std::vector<int> secondNumbers = {1, 6, 2, 3, 4, 3};

  bool equal = std::equal(numbers.begin(), numbers.end(), secondNumbers.begin(), secondNumbers.end());
  auto mismatch = std::mismatch(numbers.begin(), numbers.end(), secondNumbers.begin(), secondNumbers.end());

  std::cout << "equal: " << equal << '\n';
  if (mismatch.first != numbers.end() && mismatch.second != numbers.end())
    std::cout << "mismatch: first - " << *mismatch.first << ", second - " << *mismatch.second << '\n';
}

int main() {
  std::vector<Person> persons = {
      Person("Name 1", 25),
      Person("Name 2", 21),
      Person("Name 3", 26),
  };

  std::vector<Person> secondPersons = {
      Person("Name 1", 25),
      Person("Name 2", 21),
      Person("Name 3", 26),
  };

  bool equal = std::equal(
      persons.begin(),
      persons.end(),
      secondPersons.begin(),
      secondPersons.end(),
      [](const Person& person, const Person& secondPerson) {
    return person.name == secondPerson.name && person.age == secondPerson.age;
      });

  std::cout << equal << '\n';

  return 0;
}
