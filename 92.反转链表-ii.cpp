/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 * 
 * 思路：
 * 记录m前一个结点 第m－1个结点，排序后该结点next为排序的第一个
 * 排序完的第n － m个结点的next指向 原链表的第n＋1个结点
 * m到n的排序使用第206题的方式
 * 考虑m是1的话 不用进行头部链接了，n是最后一个的话不用考虑尾部的链接了
 * 
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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        int i = 1;
        ListNode *preHead, *startHead, *endHead, *result;
        result = head;

        if (m == n)
        {
            return result;
        }

        while (head)
        {
            if (m - 1 == i)
                preHead = head;

            if (m == i)
                startHead = head;

            if (n == i && head->next)
                endHead = head->next;

            head = head->next;
            i++;
        }

        ListNode *pre = new ListNode(0);

        if (endHead)
            pre->next = endHead;

        for (int i = 0; i < n - m + 1; i++)
        {
            ListNode *temp = startHead->next;
            startHead->next = pre->next;
            pre->next = startHead;
            startHead = temp;
        }

        if (preHead)
            preHead->next = pre->next;
        else
            result = pre->next;

        return result;
    }
};
// @lc code=end
