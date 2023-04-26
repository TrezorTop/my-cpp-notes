#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>

int main() {
    std::stack<int, std::vector<int>> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.emplace(4);

    while (!stack.empty()) {
        std::cout << stack.top() << '\n';
        stack.pop();
    }

    return 0;
}
