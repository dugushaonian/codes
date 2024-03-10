/*
 * @Author:             dugufei (dugufei@bjtu.edu.cn)
 * @Date:               2024-03-10 16:22:17
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2024-03-10 16:22:17
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board {
        {"5","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
    };
    std::cout << solution.isValidSudoku(board) << std::endl;
    vector<vector<char>> board2 {
        {"8","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
    };
    std::cout << solution.isValidSudoku(board2) << std::endl;
    return 0;
}

// clang++ -std=c++2a valid_anagram.cpp