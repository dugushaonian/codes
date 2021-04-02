#!/usr/bin/env python
# coding=utf-8

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sub_dict = {}
        for indx in range(len(nums)):
            sub = target - nums[indx]
            if sub in sub_dict.keys():
                return sub_dict[sub], indx;
            sub_dict[nums[indx]] = indx
        return -1,-1


if __name__ == "__main__":
    Solution solution;
    print(solution.twoSum([2,7,11,15], 9))
