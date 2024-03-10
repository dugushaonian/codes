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
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> char_set(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            char_set[s[i] - 'a']++;
            char_set[t[i] - 'a']--;
        }
        for (auto i : char_set) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::cout << solution.isAnagram("", "") << std::endl;
    std::cout << solution.isAnagram("anagram", "nagaram") << std::endl;
    std::cout << solution.isAnagram("rat", "car") << std::endl;
    return 0;
}

// clang++ -std=c++2a valid_anagram.cpp