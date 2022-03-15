# -*- coding: utf-8 -*-
# @Author:             dugufei (dugufei@bjtu.edu.cn)
# @Date:               2022-03-15 23:59:49
# @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
# @Last Modified time: 2022-03-16 00:01:57

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        sub_dict = {}
        for indx in range(len(nums)):
            sub = target - nums[indx]
            if sub in sub_dict.keys():
                return sub_dict[sub], indx
            sub_dict[nums[indx]] = indx
        return -1,-1


if __name__ == "__main__":
    solution = Solution()
    print(solution.twoSum([2,7,11,15], 9))
