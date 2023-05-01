#include "Person.h"

Person::Person(std::string name, int age) {
  this->name = std::move(name);
  this->age = age;
}