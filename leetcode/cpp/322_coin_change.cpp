/*
 * @Author: dugufei (dugufei@bjtu.edu.cn)
 * @Date:   2022-03-13 21:53:17
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-03-14 23:37:57
 */
#include <iostream>
#include <vector>
#include <functional>
#include <climits>
#include <unordered_map>
#include <array>

// 记忆递归
class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::unordered_map<int, int> mem;
        std::function<int(int)> dfs;
        dfs = [&](int am) {
            if (am < 0) {
                return INT_MAX;
            } else if (am == 0) {
                return 0;
            }
            int res = INT_MAX;
            for (const auto& coin : coins) {
                auto iter = mem.find(am - coin);
                if (iter != mem.end()) {
                    if (iter->second != INT_MAX) {
                        res = std::min(res, iter->second + 1);
                    }
                } else {
                    auto temp = dfs(am - coin);
                    if (temp != INT_MAX) {
                        res = std::min(res, 1 + temp);
                    }
                }
            }
            mem[am] = res;
            return res;
        };
        auto ans = dfs(amount);
        return ans == INT_MAX ? -1 : ans;
    }
};

// 动态规划 二维
class Solution2 {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        if (amount < 0) {
            return -1;
        }
        std::vector<std::vector<int>> dp(amount + 1, std::vector<int>(coins.size() + 1, amount + 1));
        for (auto i = 0; i < coins.size() + 1; ++i) {
            dp[0][i] = 0;
        }
        for (auto i = 1; i < amount + 1; ++i) {
            for (auto j = 1; j < coins.size() + 1; ++j) {
                if (i - coins[j-1] >= 0) {
                    dp[i][j] = std::min(dp[i][j-1], 1 + dp[i-coins[j-1]][j]);
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[amount][coins.size()] == amount + 1 ? -1 : dp[amount][coins.size()];
    }
};

// 动态规划 一维
class Solution3 {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        if (amount < 0) {
            return -1;
        }
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (auto coin : coins) {
            for (auto i = 1; i < amount + 1; ++i) {
                if (i >= coin) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main(int argc, char const *argv[]) {
    std::vector<int> coins{186,419,83,408};
    // Solution solution;
    // Solution2 solution;
    Solution3 solution;
    auto ans = solution.coinChange(coins, 6249);
    std::cout << ans << std::endl;
    return 0;
}

