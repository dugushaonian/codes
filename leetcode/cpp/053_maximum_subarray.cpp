/*
 * @Author: dugufei (dugufei@bjtu.edu.cn)
 * @Date:   2022-02-06 18:44:22
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-02-06 19:24:34
 */
#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int result = INT_MIN, temp = 0;
        for (const auto& i : nums) {
            temp = std::max(temp + i, i);
            result = std::max(result, temp);
        }
        return result;
    }
};

int main() {
    std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution solution;
    auto max_sub_array = solution.maxSubArray(nums);
    std::cout << max_sub_array << std::endl;
    return 0;
}

