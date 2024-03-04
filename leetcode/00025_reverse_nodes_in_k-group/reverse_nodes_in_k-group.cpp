/*
 * @Author:             dugufei (dugufei@bjtu.edu.cn)
 * @Date:               2022-04-04 21:01:30
 * @Last Modified by:   dugufei (dugufei@bjtu.edu.cn)
 * @Last Modified time: 2024-03-04 23:21:42
 */

#include <iostream>
#include <vector>

// 准备工作
// 定义单链表节点.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 构建单链表助手
ListNode* build_list(const std::vector<int>& vals) {
    int size = vals.size();
    if (size == 0) {
        return nullptr;
    }
    ListNode* root = new ListNode(vals[size - 1], nullptr);
    for (int i = size - 2; i >= 0; --i) {
        ListNode* node = new ListNode(vals[i], root);
        root = node;
    }
    return root;
}

// 打印单链表助手
void print_list(ListNode* root) {
    if (!root) {
        std::cout << "list is null!" << std::endl;
        return;
    }
    ListNode* p = root;
    while (p) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
    return;
}

// 正解
class Solution {
public:
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
};

// 万物开端----难
int main() {
    Solution solution;

    // 示例 1
    ListNode* root = build_list({1, 2, 3, 4, 5});
    ListNode * ans = solution.reverseKGroup(root, 2);
    print_list(ans);
    
    // 示例 2
    root = build_list({1, 2, 3, 4, 5});
    ans = solution.reverseKGroup(root, 3);
    print_list(ans);

    return 0;
}

// g++-13 reverse_nodes_in_k-group.cpp --std=c++17