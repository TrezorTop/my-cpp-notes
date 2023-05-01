#include <iostream>

union Union {
    short int _shortInt;
    int _int;
    float _float;
    char _char;
};

int main() {
  Union anUnion{};

  anUnion._char = 'c';
  anUnion._shortInt = 5;
  anUnion._int = 2000000;
  anUnion._float = -5.21;

  return 0;
}