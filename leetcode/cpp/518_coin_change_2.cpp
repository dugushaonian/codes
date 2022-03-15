/*
 * @Author: dugufei (dugufei@bjtu.edu.cn)
 * @Date:   2022-03-15 23:43:00
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-03-15 23:53:05
 */
#include <iostream>
#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        if (amount < 0) {
            return 0;
        }
        if (amount == 0) {
            return 1;
        }
        std::vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto coin : coins) {
            for (auto i = coin; i < amount + 1; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    std::vector<int> coins{1, 2, 5};
    auto res = solution.change(500, coins);
    std::cout << res << std::endl;
    return 0;
}
