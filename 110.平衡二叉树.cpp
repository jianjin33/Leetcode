/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stdlib.h>
#include <algorithm>

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
    int getDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return 1 + std::max(left, right);
    }

    bool isBalanced(TreeNode *root)
    {
        int height = 0;
        return checkBalance(root, height);
    }

    bool checkBalance(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if (left - right <= 1 && left - right >= -1)
        {
            return checkBalance(root->left) && checkBalance(root->right);
        }
        return false;
    }

    bool checkBalance(TreeNode *root, int &height)
    {
        if (root == nullptr)
        {
            height = 0;
            return true;
        }

        int leftHeight = 0;
        int rightHeight = 0;

        if (!checkBalance(root->left, leftHeight))
            return false;
        if (!checkBalance(root->right, rightHeight))
            return false;
        if (abs(leftHeight - rightHeight) > 1)
            return false;
        height = std::max(leftHeight, rightHeight) + 1;
        return true;
    }
};
