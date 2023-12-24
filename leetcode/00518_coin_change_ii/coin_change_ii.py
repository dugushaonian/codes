# -*- coding: utf-8 -*-
# @Author:             dugufei (dugufei@bjtu.edu.cn)
# @Date:               2022-03-15 22:54:06
# @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
# @Last Modified time: 2022-03-15 23:46:32

class Solution:
    def change(self, amount: int, coins: list[int]) -> int:
        if amount < 0:
            return 0
        if amount == 0: 
            return 1
        dp = [0 for _ in range(amount + 1)]
        dp[0] = 1
        for coin in coins:
            for i in range(coin, amount + 1):
                dp[i] += dp[i - coin]
        return dp[-1]


if __name__ == "__main__":
    solution = Solution()
    print(solution.change(500, [1, 2, 5]))
