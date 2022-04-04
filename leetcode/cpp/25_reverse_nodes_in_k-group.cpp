/*
 * @Author:             dugufei (dugufei@bjtu.edu.cn)
 * @Date:               2022-04-04 21:01:30
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2022-04-04 22:53:00
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* pre = &dummy;
        while (head) {
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail){
                    return dummy.next;
                }
            }
            std::tie(head, tail) = reverse(head, tail);
            pre->next = head;
            pre = tail;
            head = pre->next;
        }
        return dummy.next;
    }

    std::pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
        ListNode* p = head;
        while (p != tail) {
            ListNode* next = p->next;
            p->next = tail->next;
            tail->next = p;
            p = next;
        }
        return {tail, head};
    }
};

int main() {
    ListNode five(5);
    ListNode four(4, &five);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode one(1, &two);

    Solution solution;
    ListNode * ans = solution.reverseKGroup(&one, 2);
    while (ans) {
        std::cout << ans->val << std::endl;
        ans = ans->next;
    }
    return 0;
}

