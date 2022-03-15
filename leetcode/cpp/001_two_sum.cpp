/*
 * @Author:             dugufei (dugufei@bjtu.edu.cn)
 * @Date:               2021-05-18 20:33:02
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-03-16 00:02:17
 */

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int>  sub_map;
        for (int indx = 0; indx < nums.size(); ++indx) {
            int sub = target - nums[indx];
            if (sub_map.find(sub) != sub_map.end()) {
                return {sub_map[sub], indx};
            }
            sub_map[nums[indx]] = indx;
        }
        return {-1, -1};
    }
};

int main() {
    std::vector<int> nums{2,7,11,15};
    Solution solution;
    auto tag = solution.twoSum(nums, 9);
    for (auto const& iter : tag) {
        std::cout << iter << std::endl;
    }
    return 0;
}
