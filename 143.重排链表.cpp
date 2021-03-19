/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
 * 
 * 解题思路：
 *  1. 通过快慢指针找出链表的中心点
 *  2. 以中心点为界限将链表分解成两个链表
 *  3. 将第二个链表进行反转
 *  4. 合并链表
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
    void reorderList(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next)
        {
            slow = slow->next;
            fast = slow->next->next;
        }

        ListNode *first = head;
        ListNode *secend = slow;
        ListNode *revert;
        revert->next = secend;
        // 反转secend链表
        ListNode node(0), *pre = &node;
        while (secend)
        {
            ListNode* temp = secend -> next
            secend -> next = pre -> next;
            pre -> next = secend;
            secend = temp;
        }

        ListNode *start = first;
        // 合并
        while (start -> next)
        {
            start-> next = revert ->next;
            start = start ->next;
            revert = revert->next;
        }
    }
};
// @lc code=end
