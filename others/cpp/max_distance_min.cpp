/*
 * @Author: dugufei (dugufei@bjtu.edu.cn)
 * @Date:   2021-05-19 20:38:06
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2021-05-19 22:43:32
 */

#include <iostream>
#include <vector>

// 给出一条长度为 L 的线段，除了头和尾两个点以外，上面还有 n 个整数点，需要在上面再放 k 个新的点，使得相邻的两个点之间的最大距离最小，求这个最小的距离。
// https://mp.weixin.qq.com/s/muMTYAAH11gUOlrFknOjvA

// 实现的思路可以转换为: 有 n 个点, 往 n 个点中间插入 k 个点新的点, 使得相邻的两个点之间的最大距离最小，求这个最小的距离。
int solution(const std::vector<int>& n_point, int k) {
    if (n_point.size() == 0 or n_point.size() == 1) {
        return 0;
    }
    if (n_point.size() + k > *(--n_point.end()) - *n_point.begin() + 1) {
        return -1;
    }
    int l = 1, r = *(--n_point.end()) - *n_point.begin();
    while (l < r) {
        int m = l + (r - l) / 2;
        int cnt = 0;
        for (int i = 1; i < n_point.size(); ++i) {
            cnt += (n_point[i] - n_point[i-1] - 1) / m;
        }
        cnt > k ?  l = m + 1 :  r = m;
    }
    return l;
}

int main(int argc, char const *argv[]) {
    std::vector<int> n_point = {1, 8, 11, 16};
    std::cout << solution(n_point, 3) << std::endl;
    return 0;
}

