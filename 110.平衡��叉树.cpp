/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
#include <algorithm>
#include <cmath>

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution
{
private:
    int depth(TreeNode *node)
    {
        if (!node)
            return 0;

        return 1 + std::max(depth(node->left), depth(node->right));
    }

    bool checkBalanced(TreeNode *node, int &height)
    {
        if (!node)
            return true;

        int l = 0, r = 0;
        if (!checkBalanced(node->left, l))
            return false;
        if (!checkBalanced(node->right, r))
            return false;
        if (std::abs(l - r) > 1)
            return false;
        height = 1 + std::max(l, r);
        return true;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        // if (!root)
        //     return true;

        // int l = depth(root->left);
        // int r = depth(root->right);
        // if (std::abs(l - r) <= 1)
        //     return isBalanced(root->left) && isBalanced(root->right);
        // return false;
        int height = 0;
        return checkBalanced(root, height);
    }
};
// @lc code=end
