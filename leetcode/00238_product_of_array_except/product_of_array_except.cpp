/*
 * @Author:             dugufei (dugufei@bjtu.edu.cn)
 * @Date:               2024-03-10 16:53:17
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2024-03-10 16:54:52
 */
#include <iostream>
#include <vector>
#include <functional>
#include <climits>
#include <unordered_map>
#include <array>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(std::vector<int>& nums) {
        int left = 1, right = 1, n = nums.size();
        std::vector<int> res(n, 1);
        for (int i = 0; i < n; ++i) {
            res[i] *= left;
            res[n - 1 -i] *= right;
            left *= nums[i];
            right *= nums[n - 1 - i];
        }
        return res;
    }
};

void print_vec(const vector<int>& vec) {
    for (auto n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    Solution solution;
    std::vector<int> nums{1, 2, 3, 4};
    print_vec(solution.productExceptSelf(nums));
    nums = {-1,1,0,-3,3};
    print_vec(solution.productExceptSelf(nums));
    return 0;
}

