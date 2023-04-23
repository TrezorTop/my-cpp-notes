#include <iostream>
#include <string>

using std::cout, std::string;

struct MyStruct {
  int a = 5;

  void Print() { cout << this->a << '\n'; }
};

int main() {
  MyStruct myStruct;

  myStruct.Print();

  return 0;
}
