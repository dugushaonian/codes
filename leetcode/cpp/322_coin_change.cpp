/*
 * @Author: dugufei (dugufei@bjtu.edu.cn)
 * @Date:   2022-03-13 21:53:17
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-03-13 23:05:26
 */
#include <iostream>
#include <vector>
#include <functional>
#include <climits>
#include <unordered_map>

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


int main(int argc, char const *argv[]) {
    std::vector<int> coins{186,419,83,408};
    Solution solution;
    auto ans = solution.coinChange(coins, 6249);
    std::cout << ans << std::endl;
    return 0;
}

