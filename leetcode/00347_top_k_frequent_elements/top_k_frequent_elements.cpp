/*
 * @Author:             dugufei (dugufei@bjtu.edu.cn)
 * @Date:               2024-03-10 16:22:17
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2024-03-10 16:22:17
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    }
};

void print_vec(const std::vector<int> vec) {
    for (auto n : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
};

int main() {
    Solution solution;
    print_vec(solution.topKFrequent({1,1,1,2,2,3}, 2));
    print_vec(solution.topKFrequent({1}, 1));
    return 0;
}

// clang++ -std=c++2a valid_anagram.cpp