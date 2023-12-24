/*
 * @Author:             dugufei (dugufei@bjtu.edu.cn)
 * @Date:               2022-02-06 20:03:24
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-03-16 00:02:50
 */
#include <iostream>
#include <vector>
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
        // 递归
        /* if (list1->val < list2->val) { */
        /*      list1->next = mergeTwoLists(list1->next, list2); */
        /*      return list1; */
        /*  } else { */
        /*      list2->next = mergeTwoLists(list1, list2->next); */
        /*      return list2; */
        /*  } */
        /*  return nullptr; */
        // 非递归
        ListNode hat(0);
        ListNode* p = &hat;
        while (list1 && list2) {
            list1->val < list2->val ? (p->next = list1, list1 = list1->next) :
                                      (p->next = list2, list2 = list2->next); 
            p = p->next;
        }
        list1 ? p->next = list1 : p->next = list2;
        return hat.next;
    }
};

ListNode* make_list(const std::vector<int>& nums) {
    ListNode root(0);
    ListNode* p = &root;
    for (auto n : nums) {
        p->next = new ListNode(n);
        p = p->next;
    }
    return root.next;
}

std::string print_list(ListNode* head) {
    std::string res;
    while (head && head->next) {
        res = res + std::to_string(head->val) + "->";
        head = head->next;
    }
    if (head) {
        res = res + std::to_string(head->val);
    }
    return res;
}

int main(int argc, char const *argv[]) {
    ListNode* list1 = make_list({1, 1, 5, 8});
    ListNode* list2 = make_list({1, 2, 4, 5, 6});

    Solution solution;
    ListNode* merge = solution.mergeTwoLists(list1, list2);
    std::cout << print_list(merge) << std::endl;
    return 0;
}
