/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/* struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; */

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        ListNode *node = head;
        int size = 1;
        while (node->next)
        {
            size++;
            node = node->next;
        }
        int offset = k % size;

        node->next = head;// 头尾链接，一个环状
        while (--size >= offset)
        {
            node = node->next;
        }
        ListNode *first = node->next;
        node->next = nullptr;

        return first;
    }
};
// @lc code=end
