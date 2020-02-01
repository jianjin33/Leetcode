/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        // 遍历法
        // if (!head)
        //     return nullptr;

        // ListNode *todo = head;
        // while (todo->next)
        // {
        //     ListNode *next = todo->next;
        //     ListNode *temp = next->next;
        //     if (todo->val == next->val)
        //         todo->next = temp;
        //     else
        //         todo = todo->next;
        // }
        // return head;

        // 递归法
        return head 
            && (head->next = deleteDuplicates(head->next)) 
            && head->next->val == head->val ? head->next : head;
    }
};
// @lc code=end
