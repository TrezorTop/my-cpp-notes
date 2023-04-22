#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

namespace first {
    void foo() {
        cout << "first" << endl;
    }
}

namespace third::second {
    void foo() {
        cout << "second" << endl;
    }
}

int main() {
    first::foo();

    third::second::foo();

    return 0;
}