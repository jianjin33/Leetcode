/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
 * 数组分治，两个元素进行合并，
 * 合并的递归十分简单 node->next = 递归返回的两者较小的node
 */
#include <vector>

using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *node1, ListNode *node2)
    {
        if (!node1)
            return node2;

        if (!node2)
            return node1;

        if (node1->val <= node2->val)
        {
            node1->next = mergeTwoLists(node1->next, node2);
            return node1;
        }
        else
        {
            node2->next = mergeTwoLists(node1, node2->next);
            return node2;
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        if (lists.size() == 2)
        {
            return mergeTwoLists(lists[0], lists[1]);
        }

        int mid = lists.size() / 2;
        int remain = lists.size() - mid;

        vector<ListNode *> list1(mid, NULL);
        vector<ListNode *> list2(lists.size() - mid, NULL);
        for (size_t i = 0; i < lists.size(); i++)
        {
            if (i < mid)
                list1[i] = lists[i];
            else
                list2[i - mid] = lists[i];
        }

        return mergeTwoLists(mergeKLists(list1), mergeKLists(list2));
    }
};
// @lc code=end
