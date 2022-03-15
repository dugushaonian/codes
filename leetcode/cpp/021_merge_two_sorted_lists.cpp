/*
 * @Author:             dugufei (dugufei@bjtu.edu.cn)
 * @Date:               2022-02-06 20:03:24
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-03-16 00:02:50
 */
#include <iostream>

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }
        ListNode temp(-1);
        ListNode* p = &temp;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        p->next = list1 ? list1 : list2;
        return temp.next;
    }
};

int main(int argc, char const *argv[]) {
    ListNode four1(4);
    ListNode two(2, &four1);
    ListNode one1(1, &two);

    ListNode four2(4);
    ListNode three(3, &four2);
    ListNode one2(1, &three);
    Solution solution;
    ListNode* merge = solution.mergeTwoLists(&one1, &one2);
    while (merge) {
        std::cout << merge->val << std::endl;
        merge = merge->next;
    }
    return 0;
}
