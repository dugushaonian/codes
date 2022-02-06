/*
 * @Author: dugufei (dugufei@bjtu.edu.cn)
 * @Date:   2022-02-06 20:52:51
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-02-06 20:59:23
 */
#include <iostream>

// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode temp(-1, head);
        ListNode* p = &temp;
        ListNode* q = &temp;
        for (int i = 0; i < n; i++) {
            q = q->next;
        }
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        q = p->next;
        p->next = p->next->next;
        delete q;
        return temp.next;
    }
};

int main(int argc, char const *argv[]) {
    ListNode* five = new ListNode(5);
    ListNode* four = new ListNode(4, five);
    ListNode* three = new ListNode(3, four);
    ListNode* two = new ListNode(2, three);
    ListNode* one = new ListNode(1, two);
    Solution solution;
    ListNode* removed = solution.removeNthFromEnd(one, 2);
    while (removed) {
        std::cout << removed->val << std::endl;
        ListNode* temp = removed;
        removed = removed->next;
        delete temp;
    }
    return 0;
}
