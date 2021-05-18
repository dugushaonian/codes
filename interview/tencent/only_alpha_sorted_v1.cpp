#include <iostream>

std::string& sort(std::string& str) {
    if (str.empty() || str.size() == 1) {
        return str;
    }
    for (size_t i = str.size(); i > 0; --i) {
        for (size_t j = 0; j < i - 1; ++j) {
            if (!isalpha(str[j])) {
                continue;
            }
            for (size_t k = j + 1; k < i; ++k) {
                if (!isalpha(str[k])) {
                    continue;
                }
                if (std::tolower(str[k]) - std::tolower(str[j]) < 0) {
                    std::swap(str[j], str[k]);
                }
                break;
            }
        }
    }
    return str;
}

int main() {
    std::string str = "A Famous Saying: Much Ado About Nothing (2012/8).";
    /* A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8). */
    std::cout << sort(str) << std::endl;
    return 0;
}
