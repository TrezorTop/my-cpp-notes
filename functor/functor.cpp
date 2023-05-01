#include <iostream>

class Functor {
  public:
    int operator()(int a, int b) {
      this->integer = a + b;
      std::cout << "Previous result " << integer << '\n';
      return a + b;
    }

  private:
    int integer;
};

int main() {
  Functor functor{};

  functor(1, 3);
  functor(1, 4);
  functor(1, 5);
  functor(1, 6);
  functor(1, 7);
}
