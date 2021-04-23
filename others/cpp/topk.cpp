#include <iostream>
#include <queue>

int main() {
    int k = 0;
    std::cin >> k;
    int tmp = 0;
    int i = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    while (std::cin >> tmp) {
        if (i++ < k) {
            min_heap.push(tmp);
            continue;
        }
        if (tmp <= min_heap.top()) {
            continue;
        }
        min_heap.pop();
        min_heap.push(tmp);
    }
    while (!min_heap.empty()) {
        std::cout << min_heap.top() << std::endl;
        min_heap.pop();
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

