#include <iostream>
#include <list>
#include <queue>
#include <string>

int main() {
    std::priority_queue<int> priorityQueue;

    priorityQueue.push(1);
    priorityQueue.push(2);
    priorityQueue.push(3);
    priorityQueue.push(4);

    priorityQueue.emplace(5);

    priorityQueue.pop();

    std::cout << "priorityQueue.top() " << priorityQueue.top() << '\n';

    while (!priorityQueue.empty())
        priorityQueue.pop();

    std::cout << "priorityQueue.size() " << priorityQueue.size() << '\n';

    return 0;
}
