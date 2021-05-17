#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <array>
#include <set>


std::string& sort(std::string& str) {
    if (str.empty() || str.size() == 1) {
        return str;
    }
    std::unordered_map<char, std::vector<char>> _char2vec;
    std::set<char> _bitset;
    for (auto c : str) {
        if (!isalpha(c)) {
            continue;
        }
        if (auto iter = _char2vec.find(std::tolower(c)); iter == _char2vec.end()) {
            std::vector<char> c_vec;
            _char2vec[std::tolower(c)] = c_vec;
        }
        _char2vec[std::tolower(c)].push_back(c);
        _bitset.insert(::tolower(c));
    }

    size_t index = 0;
    for (auto c : _bitset) {
        auto vec = _char2vec[c];
        for (auto c_o : vec) {
            while (!isalpha(str.at(index))) {
                index++;
            }
            str[index++] = c_o;
        }

    }
    return str;
}

using namespace std;

int main() {
    // std::string str = "A Famous Saying: Much Ado About Nothing (2012/8).";
    std::string str;
    std::getline(std::cin, str, '\n');
    std::string str_sorted = sort(str);
    cout << str_sorted << endl;
}

