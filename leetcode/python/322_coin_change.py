# -*- coding: utf-8 -*-
# @Author: dugufei (dugufei@bjtu.edu.cn)
# @Date:   2022-03-14 23:43:34
# @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
# @Last Modified time: 2022-03-15 00:08:59

from cmath import inf
from functools import lru_cache

class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        @lru_cache(None)
        def dfs(am: int) -> int:
            if am < 0:
                return float("inf")
            if am == 0:
                return 0
            ans = float("inf")
            for coin in coins:
                ans = min(ans, dfs(am - coin) + 1)
            return ans
        res = dfs(amount)
        return -1 if res == float("inf")  else res


class Solution2:
    def coinChange(self, coins: list[int], amount: int) -> int:
        if amount < 0:
            return -1
        dp = [[amount + 1 for _ in range(len(coins) + 1)] for _ in range(amount + 1)]
        for i in range(len(coins) + 1):
            dp[0][i] = 0
        for i in range(1, amount + 1):
            for j in range(1, len(coins) + 1):
                if i >= coins[j - 1]:
                    dp[i][j] = min(dp[i][j-1], 1 + dp[i - coins[j-1]][j])
                else:
                    dp[i][j] = dp[i][j-1]
        return -1 if dp[-1][-1] == amount + 1 else dp[-1][-1]


class Solution3:
    def coinChange(self, coins: list[int], amount: int) -> int:
        if amount < 0:
            return -1
        dp = [amount + 1 for _ in range(amount + 1)]
        dp[0] = 0
        for coin in coins:
            for i in range(1, amount + 1):
                if i - coin >= 0:
                    dp[i] = min(dp[i], dp[i-coin] + 1)
        return -1 if amount + 1 == dp[-1] else dp[-1]


if __name__ == "__main__":
    solution = Solution()
    solution = Solution2()
    solution = Solution3()
    print(solution.coinChange([186,419,83,408], 6249))
