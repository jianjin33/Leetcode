/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 * 思路：
 * 定义一个结点 ,然后开始遍历链表，
 * 1. 记录链表中当前结点指向的下个结点，临时变量
 * 2. 遍历的结点next指向定义结点的next
 * 3. 定义的结点next指向当前遍历的结点
 *  下次进来的结点next再指向定义结点的next 也就是第二步
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
 * 
 * 
 * 
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode node(0), *pre = &node;
        while (head)
        {
            ListNode *temp = head->next;
            head->next = pre->next;
            pre->next = head;
            head = temp;
        }
        return pre->next;
    }
};
// @lc code=end
