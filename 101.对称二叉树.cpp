/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr) return true;
        return checkSymetric(root->left, root->right);
    }

    bool checkSymetric(TreeNode *leftNode, TreeNode *rightNode)
    {
        if (leftNode == nullptr && rightNode == nullptr) return true;
        if (leftNode == nullptr || rightNode == nullptr) return false;
        if (leftNode->val == rightNode->val)
        {
           return checkSymetric(leftNode->left, rightNode->right) && checkSymetric(leftNode->right, rightNode->left);
        }
        return false;
    }
};

// @lc code=end
