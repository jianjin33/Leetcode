/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector> // 不添加STL 下面的NULL提示找不到。当然也可以使用nullptr代替NULL

// #ifndef _COMMON
// #define _COMMON
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(nullptr) {}
// };
// #endif

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // 递归3个退出的条件：p和q两者是null或其中一个为null，进行比较，
        // 1：都为null返回true；2：其中一个为null会返回false
        if (!p || !q)
            return p == q;
        // p和q都不为null走这里，先判断val，不同直接返回false(3：也是一个退出条件)，相同继续递归左右节点
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end 时间复杂度：O(n)，n为树的节点个数
