// input
// 【小明,李明】是一个【好学生,优秀的学生,聪明的学生】
// 中括号没有嵌套，中括号的数量不一定

// output
// 小明是一个好学生。
// 李明是一个好学生。
// 小明是一个优秀的学生。
// 小明是一个聪明的学生。
// 李明是一个优秀的学生。
// 李明是一个聪明的学生。

// #include <iostream>
// #include <vector>

// struct Node {
//     std::string data;
//     std::vector<Node*> nexts;
// };

// Node* build_grouph(const std::string& str) {
//     Node* root = new Node();
//     while (!root->nexts.empty()) {
//         /* code */
//     }
    
//     return root;
// }
// std::vector<std::string> solution(const std::string& str) {
//     Node* root = build_grouph(str);

// }
// int main(int argc, char const *argv[]) {
//     return 0;
// }

// 1.返回最大子串和
// 4，-3，-5，6，8，-1，2

#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return -1;
        }
        int res = nums[0];
        int temp = res;
        size_t index = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            temp = temp + nums[i];
            if (temp < 0) {
                index 
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution solution;
    std::vector<int32_t> input = {4,-3,-5,6,8,-1,2};
    std::cout << solution.maxSubArray(input) << std::endl;
    return 0;
}
