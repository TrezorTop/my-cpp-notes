#include <iostream>
#include <string>

using namespace std;

class MyException : public runtime_error {
public:
  MyException(char *message, int state) : runtime_error(message) {
    this->state = state;
  }

  int GetState() const { return this->state; }

private:
  int state;
};

int main() {

  try {
    throw MyException("explanation message", 50);
  } catch (const MyException &exception) {
    cout << "what(): " << exception.what() << endl;
    cout << "state: " << exception.GetState() << endl;
  }

  return 0;
}
