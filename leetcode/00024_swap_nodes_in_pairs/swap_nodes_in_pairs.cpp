/*
 * @Author:             dugufei (dugufei@bjtu.edu.cn)
 * @Date:               2022-04-04 21:01:30
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-04-04 21:21:28
 */

#include <iostream>

 //* Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyHead(0, head);
        ListNode *pre = &dummyHead;
        while (pre->next && pre->next->next) {
            ListNode* p = pre->next;
            ListNode* q = pre->next->next;
            p->next = q->next;
            q->next = p;
            pre->next = q;
            pre = p;
        }
        return dummyHead.next;
    }
};

int main() {
    ListNode four(4);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode one(1, &two);

    Solution solution;
    ListNode * ans = solution.swapPairs(&one);
    while (ans) {
        std::cout << ans->val << std::endl;
        ans = ans->next;
    }
    return 0;
}

