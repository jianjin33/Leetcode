/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 * 思想：用两个指针，第一个不动从头开始，第二个从第n个开始，
 * 同时遍历，当第二个指针到达尾部时，说明第一个指向的就时需要删除的结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode preHead(-1);
        preHead.next = head;

        ListNode *slow = &preHead, *fast = &preHead;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return preHead.next;
    }
};
// @lc code=end
