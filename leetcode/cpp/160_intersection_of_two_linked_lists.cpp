#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode* ptr_a = headA;
        ListNode* ptr_b = headB;
        while(ptr_a != ptr_b) {
            ptr_a = ptr_a ? ptr_a->next : headB;
            ptr_b = ptr_b ? ptr_b->next : headA;
        }
        return ptr_a;
    }
};

int main() {
    ListNode* headA = new ListNode(4);
    ListNode* headB = new ListNode(5);
    ListNode* headC = new ListNode(8);
    headA->next = new ListNode(1);
    headA->next->next = headC;
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headC;
    headC->next = new ListNode(4);
    headC->next->next = new ListNode(5);
    Solution solution;
    ListNode* ans = solution.getIntersectionNode(headA, headB);
    if (!ans) {
        std::cout << "null" << std::endl;
    } else {
        std::cout << "val: " << ans->val << std::endl;
    }

    ListNode* headD = new ListNode(0);
    ListNode* headE = new ListNode(3);
    ListNode* headF = new ListNode(2);
    headD->next = new ListNode(9);
    headD->next->next = new ListNode(1);
    headD->next->next->next = headF;
    headE->next = headF;
    headF->next = new ListNode(4);
    ans = solution.getIntersectionNode(headD, headE);
    if (!ans) {
        std::cout << "null" << std::endl;
    } else {
        std::cout << "val: " << ans->val << std::endl;
    }

    ListNode* headG = new ListNode(2);
    ListNode* headH = new ListNode(1);
    headG->next = new ListNode(6);
    headG->next->next = new ListNode(4);
    headH->next = new ListNode(5);
    ans = solution.getIntersectionNode(headG, headH);
    if (!ans) {
        std::cout << "null" << std::endl;
    } else {
        std::cout << "val: " << ans->val << std::endl;
    }
    return 0;
}

