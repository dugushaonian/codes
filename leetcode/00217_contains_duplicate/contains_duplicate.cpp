/*
 * @Author:             dugufei (dugufei@bjtu.edu.cn)
 * @Date:               2024-03-10 16:22:17
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2024-03-10 16:22:17
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> mem_set;
        for (auto n : nums) {
            if (mem_set.count(n) > 0) {
                return true;
            }
            mem_set.insert(n);
        }
        return false;
    }
};

int main() {
    Solution solution;
    std::cout << solution.containsDuplicate({1}) << std::endl;
    std::cout << solution.containsDuplicate({1, 2, 3, 1}) << std::endl;
    std::cout << solution.containsDuplicate({1, 2, 3, 4}) << std::endl;
    std::cout << solution.containsDuplicate({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}) << std::endl;

    return 0;
}

// clang++ -std=c++2a valid_anagram.cpp