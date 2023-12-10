/*
 * @Author:             dugufei (dugufei@bjtu.edu.cn)
 * @Date:               2022-02-06 20:19:22
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-03-16 00:03:01
 */
#include <iostream>
#include <vector>
#include <climits>

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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        ListNode* p = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            p = mergeTwoLists(p, lists[i]);
        }
        return p;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode temp(-1);
        for(ListNode* p = &temp; list1 || list2; p = p->next) {
            int val1 = list1 ? list1->val : INT_MAX;
            int val2 = list2 ? list2->val : INT_MAX;
            if (val1 <= val2) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
        }
        return temp.next;
    }
};

int main(int argc, char const *argv[]) {
    ListNode five(5);
    ListNode four1(4, &five);
    ListNode one1(1, & four1);

    ListNode four2(4);
    ListNode three(3, &four2);
    ListNode one2(1, &three);

    ListNode six(6);
    ListNode two(2, &six);

    std::vector<ListNode*> lists{&one1, &one2, &two};
    Solution solution;
    ListNode* sorted = solution.mergeKLists(lists);
    while (sorted) {
        std::cout << sorted->val << std::endl;
        sorted = sorted->next;
    }
    return 0;
}
