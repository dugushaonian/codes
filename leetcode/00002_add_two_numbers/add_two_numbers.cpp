/*
 * @Author:             dugufei (dugufei@bjtu.edu.cn)
 * @Date:               2021-05-18 20:33:20
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-03-16 00:02:30
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode(0);
        ListNode* ptr = answer;
        ListNode* p = l1;
        ListNode* q = l2;
        int carry = 0;

        while (p || q) {
            p = p ? carry += p->val, p = p->next : p;
            q = q ? carry += q->val, q = q->next : q;
            ptr->next = new ListNode(carry % 10);
            carry = carry / 10;
            ptr = ptr->next;
        }
        if (carry != 0) {
            ptr->next = new ListNode(carry);
        }
        ptr = answer->next;
        delete answer;
        return ptr;
    }
};

int main() {
    Solution solution;
    ListNode l1(2);
    l1.next = new ListNode(4);
    l1.next->next = new ListNode(3);
    l1.next->next->next = nullptr;

    ListNode l2(5);
    l2.next = new ListNode(6);
    l2.next->next = new ListNode(4);
    l2.next->next->next = nullptr;

    ListNode* ans = solution.addTwoNumbers(&l1, &l2);
    ListNode* ptr = ans;
    while (ptr != nullptr) {
        std::cout << ptr->val << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
    return 0;
}
