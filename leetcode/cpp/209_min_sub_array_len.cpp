/*
 * @Author: dugufei (dugufei@bjtu.edu.cn)
 * @Date:   2021-05-18 20:33:09
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2021-05-18 20:48:59
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        size_t j = 0;
        int sum = 0;
        size_t res = nums.size() + 1;
        for (size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= target) {
                res = std::min(res, i - j + 1);
                sum -= nums[j++];
            }
            if (res == 1) {
                break;
            }
        }
        return res > nums.size() ? 0 : res;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    std::vector<int> vec1 = {2,3,1,2,4,3};
    std::cout << solution.minSubArrayLen(7, vec1) << std::endl;

    std::vector<int> vec2 = {1,4,4};
    std::cout << solution.minSubArrayLen(4, vec2) << std::endl;

    std::vector<int> vec3 = {1,1,1,1,1,1,1,1};
    std::cout << solution.minSubArrayLen(11, vec3) << std::endl;
    return 0;
}
