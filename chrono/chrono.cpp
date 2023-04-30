#include <array>
#include <chrono>
#include <functional>
#include <iostream>
#include <list>
#include <vector>


void countFunctionTime(const std::string& name, const std::function<void()>& function) {
    auto start = std::chrono::high_resolution_clock::now();

    function();

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << name << " time: " << (end - start).count() << '\n';
}

int main() {
    std::vector<int> vector;
    std::list<int> list;
    std::array<int, 3> array{};

    countFunctionTime("vector", [&vector]() -> void {
        vector.push_back(1);
        vector.push_back(2);
        vector.push_back(3);
    });
    countFunctionTime("list", [&list]() -> void {
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
    });
    countFunctionTime("array", [&array]() -> void {
        for (int i = 0; i < 3; ++i) {
            array[i] = i + 1;
        }
    });

    return 0;
}
