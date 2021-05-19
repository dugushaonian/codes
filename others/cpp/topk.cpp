/*
 * @Author: dugufei (dugufei@bjtu.edu.cn)
 * @Date:   2021-05-19 22:51:50
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2021-05-19 23:56:19
 */

#include <iostream>
#include <queue>

template<typename RandomIterator, typename Compare = std::greater<typename RandomIterator::value_type>>
inline std::vector<typename RandomIterator::value_type>
topk(RandomIterator first, RandomIterator last, size_t k, Compare compare = Compare()) {
    std::priority_queue<typename RandomIterator::value_type, std::vector<typename RandomIterator::value_type>, Compare> heap;
    std::vector<typename RandomIterator::value_type> res;
    size_t i = 0;
    while (first != last) {
        if (i++ < k) {
            heap.push(*first);
            first++;
            continue;
        }
        if (!(compare(*first, heap.top()))) {
            first++;
            continue;
        }
        heap.pop();
        heap.push(*first);
        first++;
    }
    while (!heap.empty()) {
        res.push_back(heap.top());
        heap.pop();
    }
    return res;
}

int main() {
    std::vector<int32_t> in = {4, 2, 5, 3, 5, 1, 4, 6, 7, 8, 9};
    auto out = topk(in.begin(), in.end(), 4);
    for (auto i : out) {
        std::cout << i << std::endl;
    }

    std::cout << "-------------" << std::endl;

    out = topk(in.begin(), in.end(), 4, std::less<int32_t>());
    for (auto i : out) {
        std::cout << i << std::endl;
    }
    
    std::cout << "-------------" << std::endl;

    std::string str = "adsffagdfa";
    auto str_out = topk(str.begin(), str.end(), 4);
    for (auto i : str_out) {
        std::cout << i << std::endl;
    }
    
    std::cout << "-------------" << std::endl;

    str_out = topk(str.begin(), str.end(), 4, std::less<char>());
    for (auto i : str_out) {
        std::cout << i << std::endl;
    }
    return 0;
}

