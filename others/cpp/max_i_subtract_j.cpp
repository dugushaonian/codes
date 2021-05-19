/*
 * @Author: dugufei (dugufei@bjtu.edu.cn)
 * @Date:   2021-05-19 21:42:54
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2021-05-19 22:43:52
 */

#include <iostream>
#include <vector>

// 给出一个数组 A，找到最大的 A[i] - A[j]，要求 i > j。
// https://mp.weixin.qq.com/s/muMTYAAH11gUOlrFknOjvA

int solution(const std::vector<int32_t>& nums) {
    int32_t res = INT32_MIN;
    if (nums.size() == 0 or nums.size() == 1) {
        return res;
    }
    int32_t minnum = nums[0]; 
    for (size_t i = 1; i < nums.size(); ++i) {
        res = std::max(res, nums[i]-minnum);
        minnum = std::min(minnum, nums[i]);
    }
    return res;
}

int main(int argc, char const *argv[]) {
    std::vector<int32_t> nums = {1,5,8,0,1,3,2,8,1,8,3};
    std::cout << solution(nums) << std::endl;
    return 0;
}

