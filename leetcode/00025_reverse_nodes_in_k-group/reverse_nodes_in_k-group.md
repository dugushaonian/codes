# 25. K 个一组反转链表

## 题目描述

[LeetCode](https://leetcode.cn/problems/reverse-nodes-in-k-group/) 第 25 题

给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

---

示例 1：

<img src="./01.png#pic_center" alt="示例1" width="300" height="120"/>

```
输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
```

示例 2：

<img src="./02.png#pic_center" alt="示例2" width="300" height="120"/>

```
输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
```

---

提示：

链表中的节点数目为 n

1 <= k <= n <= 5000

0 <= Node.val <= 1000

进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗?

---

## 题解

这道题，思路很清晰，就是直接根据题意 k 个一组进行反转即可。如下图 k = 2 时：先找到第一组 node 1 和 node 2，然后进行反转；再找到第二组 node 3 和 node 4，然后进行反转；最后 node 5 不够 k，单独一组。

<img src="./03.png" align='middle' alt="题解" width="650" height="300"/>

思路很简单，然而，这是一道困难题，短时间内实现起来还是有很多细节很难考虑全的，特别是 ACM 式的还要自己实现构建链表打印链表等时，如果不是经常刷题的会感觉很是容易出错的。


``` c++
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
```

[完整代码](./reverse_nodes_in_k-group.cpp)