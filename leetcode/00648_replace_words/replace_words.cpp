#include <iostream>
#include <vector>
#include <set>
#include <ranges>
#include <iomanip>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        auto split = [&] (char sep) {
            std::vector<std::string_view> splited;
            auto fastiter = sentence.begin();
            auto slowiter = sentence.begin();
            while (slowiter != sentence.end()) {
                if (*slowiter == sep) {
                    splited.emplace_back(std::string_view(fastiter, slowiter));
                    fastiter = slowiter + 1;
                }
                slowiter++;
            }
            if (fastiter != slowiter) {
                splited.emplace_back(std::string_view(fastiter, slowiter));
            }
            return splited;
        };
        std::set<string_view> dictionary_set;
        for (auto& dic : dictionary) {
            dictionary_set.emplace(dic);
        }
        // std::string_view sen(sentence);
        // auto words = std::views::split(sentence, ' '); // c++20
        auto words = split(' ');
        std::string ans;
        for (auto& word : words) {
            int i = 0;
            for (; i < word.size(); ++i) {
                if (dictionary_set.count(std::string_view(word.begin(), word.begin() + i + 1))) {
                    ans = ans + std::string(word.begin(), word.begin() + i + 1);
                    break;
                }
            }
            if (i == word.size()) {
                ans += std::string(word.begin(), word.end());
            }
            ans += " ";
        }
        if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    Solution s;
    std::string ans = s.replaceWords(dictionary, sentence);
    std::cout << ans << std::endl;
    dictionary = {"a","b","c"};
    sentence = "aadsfasf absbs bbab cadsfafs";
    ans = s.replaceWords(dictionary, sentence);
    std::cout << ans << std::endl;
    dictionary = {"a", "aa", "aaa", "aaaa"};
    sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
    ans = s.replaceWords(dictionary, sentence);
    std::cout << ans << std::endl;
    dictionary = {"catt","cat","bat","rat"};
    sentence = "the cattle was rattled by the battery";
    ans = s.replaceWords(dictionary, sentence);
    std::cout << ans << std::endl;
    dictionary = {"ac","ab"};
    sentence = "it is abnormal that this solution is accepted";
    ans = s.replaceWords(dictionary, sentence);
    std::cout << ans << std::endl;
    return 0;
}

