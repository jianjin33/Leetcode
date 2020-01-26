/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
            return false;

        int newSum = sum - root->val;

        if (!root->left && !root->right)
            return newSum == 0;

        return hasPathSum(root->left, newSum) | hasPathSum(root->right, newSum);
    }
};
// @lc code=end
