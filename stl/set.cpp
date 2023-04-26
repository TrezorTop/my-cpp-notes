#include <iostream>
#include <set>

int main() {
    std::set<int> set;

    set.insert(5);
    set.insert(1);
    set.insert(8);
    set.insert(9);
    set.insert(2);
    set.insert(5);
    set.insert(0);

    //  set.erase(5);

    auto iterator = set.find(5);

    if (iterator == set.end()) std::cout << &iterator << '\n'
                                         << '\n';

    for (auto& item: set) {
        std::cout << item << '\n';
    }
}
