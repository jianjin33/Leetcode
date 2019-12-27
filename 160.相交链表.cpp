/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 * 思路：
 * 一、set 第一条链表分别insert node地址，第二条链表insert时 开始重复的哪个点就是交叉点
 * 二、先对其，长的截取多余的，然后逐个往后遍历，当相同结点 就找到 O(n)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        auto currA = headA, currB = headB;
        int countA = 0, countB = 0;

        while (currA)
        {
            currA = currA->next, countA++;
        }
        while (currB)
        {
            currB = currB->next, countB++;
        }
        int diff = std::abs(countA - countB);
        if (countB > countA)
        {
            swap(headA, headB);
        }
        while (diff--)
        {
            headA = headA->next;
        }
        while (headA != headB)
        {
            headA = headA->next, headB = headB->next;
        }
        return headA;
    }

    int GetLength(ListNode *node)
    {
        int i = 0;
        while (node)
        {
            i++;
            node = node->next;
        }
        return i;
    }

    ListNode *ResizeNode(ListNode *node, int value)
    {
        while (node && value--)
        {
            node = node->next;
        }
        return node;
    }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
    {
        int aLength = GetLength(headA);
        int bLength = GetLength(headB);

        int value = aLength - bLength;
        int size = value ? bLength : aLength;

        if (value > 0)
            headA = ResizeNode(headA, value);
        else if (value < 0)
            headB = ResizeNode(headB, value);

        while (size--)
        {
            if (headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
// @lc code=end
