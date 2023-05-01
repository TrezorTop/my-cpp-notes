#include <iostream>

#include "point/Point.h"
#include "sum/sum.h"

int main() {
  std::cout << "sum: " << sum(1, 5) << '\n' << '\n';

  point::Point point{};

  point.setX(5);
  point.setY(2);

  std::cout << "point: " << point.getX() << ' ' << point.getY() << '\n';
}
