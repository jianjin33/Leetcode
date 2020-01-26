/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        if (!l1 || l2 && l1->val > l2->val)
            swap(l1, l2);
        if (l1)
            l1->next = mergeTwoLists(l1->next, l2);
        return l1;

        // ListNode *tail;
        // ListNode *temp;

        // if (!l1 && !l2)
        //     return nullptr;

        // if (!l1 || !l2)
        //     return l1 ? l1 : l2;

        // if (l1->val < l2->val)
        // {
        //     tail = l1;
        //     l1 = l1->next;
        // }
        // else
        // {
        //     tail = l2;
        //     l2 = l2->next;
        // }
        // ListNode *result = tail;

        // while (l1 && l2)
        // {
        //     if (l1->val < l2->val)
        //     {
        //         temp = l1->next;
        //         tail->next = l1;
        //         l1 = temp;
        //     }
        //     else
        //     {
        //         temp = l2->next;
        //         tail->next = l2;
        //         l2 = temp;
        //     }
        //     tail = tail->next;
        // }

        // if (l1)
        //     tail->next = l1;

        // if (l2)
        //     tail->next = l2;
        // return result;
    }
};
// @lc code=end
