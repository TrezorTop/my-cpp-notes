#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <thread>

int sum(int a, int b) {
    std::cout << "calculating " << a << " + " << b << '\n';

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::cout << "calculating is done!" << '\n';

    return a + b;
}

int main() {
    std::cout << "main start" << '\n';

    int result;

    std::thread thread([&result]() {
        result = sum(2, 5);
    });

    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread ID: " << std::this_thread::get_id() << ", main" << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    thread.join();

    std::cout << "result is " << result << '\n';

    std::cout << "main end" << '\n';
    return 0;
}
