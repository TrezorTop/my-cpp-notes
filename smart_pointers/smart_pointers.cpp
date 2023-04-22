#include <iostream>
#include <string>
#include <memory>

using std::cout, std::string;

// DEPRECATED
void autoPointer() {
    std::auto_ptr<int> ap(new int(5));

    std::auto_ptr<int> ap2(ap);
}

void uniquePointer() {
    std::unique_ptr<int> up(new int(5));

    std::unique_ptr<int> up2(std::move(up));

//    std::move analog
//    up2.swap(up);

//    raw pointer
    int* ptr = up2.get();

    cout << ptr << '\n';
}

void sharedPointer() {
    std::shared_ptr<int> sp(new int(5));

    std::shared_ptr<int> sp2(sp);
}

int main() {
    sharedPointer();

    return 0;
}