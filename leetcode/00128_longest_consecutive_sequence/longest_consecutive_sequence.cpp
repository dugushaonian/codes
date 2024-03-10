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
    int longestConsecutive(const vector<int>& nums) {
        int res = 0;
        std::unordered_map<int, int> mp;
        for (auto n : nums) {
            if (mp.find(n) != mp.end()) {
                continue;
            }
            int left = mp.find(n - 1) != mp.end() ? mp[n - 1] : 0;
            int right = mp.find(n + 1) != mp.end() ? mp[n + 1] : 0;
            mp[n] = left + 1 + right;
            mp[n - left] = mp[n];
            mp[n + right] = mp[n];
            res = max(res, mp[n]);
        }
        return res;
    }
};

int main() {
    Solution solution;
    std::cout << solution.longestConsecutive({100,4,200,1,3,2}) << std::endl;
    std::cout << solution.longestConsecutive({0,3,7,2,5,8,4,6,0,1}) << std::endl;
    return 0;
}

// clang++ -std=c++2a valid_anagram.cpp