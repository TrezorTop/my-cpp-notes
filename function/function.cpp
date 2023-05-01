#include <functional>
#include <iostream>
#include <thread>

void Foo() {
  std::cout << "Foo" << '\n';
}
void Bar() {
  std::cout << "Bar" << '\n';
}
int sum(int a, int b) {
  return a + b;
}
void functionalExample() {
  std::function<void()> function;
  function = Bar;
  //  function();

  std::function<int(int, int)> sumFunction;

  sumFunction = sum;

  std::cout << sumFunction(2, 5) << '\n';
}

void calculate(int a, int b, const std::function<void(int)>& callback) {
  std::cout << "Calculating..." << '\n';

  std::this_thread::sleep_for(std::chrono::milliseconds(3000));

  std::cout << "Done!" << '\n';

  callback(a + b);
}
void lambdaExample() {
  int result;

  auto callback = [&result](int calculationResult) {
    result = calculationResult;
    std::cout << "Called lambda function " << '\n';
  };

  calculate(5, 4, callback);

  std::cout << result << '\n';
}

int main() {
  auto function = [](int a, int b) { return a + b; };

  auto result = function(5, 9);

  std::cout << result << '\n';

  return 0;
}
