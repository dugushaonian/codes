/*
 * @Author: dugufei (dugufei@bjtu.edu.cn)
 * @Date:   2022-02-06 19:41:00
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-02-06 19:54:32
 */

#include <iostream>
#include <climits>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = nullptr;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode temp(-1);
        for (ListNode* p = &temp; l1 || l2; p = p->next) {
            int val1 = l1 ? l1->val : INT_MAX;
            int val2 = l2 ? l2->val : INT_MAX;
            if (val1 <= val2) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }
        return temp.next;
    }
};

int main(int argc, char const *argv[]) {
    ListNode three(3);
    ListNode one(1, &three);
    ListNode two(2, &one);
    ListNode four(4, &two);
    Solution solution;
    ListNode* sorted = solution.sortList(&four);
    while (sorted) {
        std::cout << sorted->val << std::endl;
        sorted = sorted->next;
    }
    return 0;
}
