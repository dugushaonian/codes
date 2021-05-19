/*
 * @Author: dugufei (dugufei@bjtu.edu.cn)
 * @Date:   2021-05-19 21:55:46
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2021-05-19 22:22:31
 */
#include <iostream>
#include <stack>

// 给定一个字符串，对该字符串进行删除操作，保留 k 个字符且相对位置不变，使字典序最小。
// https://mp.weixin.qq.com/s/muMTYAAH11gUOlrFknOjvA

std::string solution(const std::string& str, size_t k) {
    if (str.size() < k) {
        return str;
    }
    k = str.size() - k;
    std::stack<char> st;
    for (size_t i = 0; i < str.size(); ++i) {
        while (!st.empty() and st.top() > str[i] and k > 0) {
            st.pop();
            k--;
        }
        st.push(str[i]);
        
    }
    std::string res;
    while (!st.empty()) {
        !(k > 0) ?  res = st.top() + res, k : k--;
        st.pop();
    }
    return res;
    
}

int main(int argc, char const *argv[]) {
    std::cout << solution("dugufei", 2) << std::endl;
    return 0;
}

