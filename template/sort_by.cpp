#include <iostream>
#include <ranges>
#include <vector>

struct Animal {
    std::string name;
    int age;
    double weight;
};

enum class AnimalSortKey {
  AGE,
  WEIGHT,
  RELATIVE_WEIGHT,  // weight divided by age
};

template <typename Container, typename KeyMapper>
void SortBy(Container& container, KeyMapper keyMapper, bool reverse = false) {
  sort(container.begin(), container.end(), [&keyMapper, &reverse](const auto& lhs, const auto& rhs) {
    return reverse ? keyMapper(lhs) > keyMapper(rhs) : keyMapper(lhs) < keyMapper(rhs);
  });
}

int main() {
  std::vector<Animal> animals = {
      {"Archi", 10, 5},
      {"Centurion", 5, 1.5},
      {"Bullet", 2, 4.5},
      {"Danny", 12, 3.1},
  };

  std::cout << "Sort by name" << '\n';
  SortBy(animals, [](const Animal& animal) { return animal.name; });
  for (const Animal& animal : animals) {
    std::cout << animal.name << ' ' << animal.age << ' ' << animal.weight << '\n';
  }
  std::cout << '\n';

  std::cout << "Sort by age" << '\n';
  SortBy(
      animals, [](const Animal& animal) { return animal.age; }, true
  );
  for (const Animal& animal : animals) {
    std::cout << animal.name << ' ' << animal.age << ' ' << animal.weight << '\n';
  }
  std::cout << '\n';

  std::cout << "Sort by weight" << '\n';
  SortBy(
      animals, [](const Animal& animal) { return animal.weight; }, true
  );
  for (const Animal& animal : animals) {
    std::cout << animal.name << ' ' << animal.age << ' ' << animal.weight << '\n';
  }

  return 0;
}