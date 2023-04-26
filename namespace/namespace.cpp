#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

namespace first {
    void foo() { cout << "first" << endl; }
}// namespace first

namespace third::second {
    void foo() { cout << "second" << endl; }
}// namespace third::second

int main() {
    first::foo();

    third::second::foo();

    return 0;
}