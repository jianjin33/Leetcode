/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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

#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        /*         if (!root)
            return true;

        if (!isValid(root->left, root->val, true) || !isValid(root->right, root->val, false))
        {
            return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
 */

        TreeNode *pre = NULL;
        return isValid2(root, pre);
    }

    bool isValid(TreeNode *root, int bound, bool isLeft)
    {
        return !root || (isLeft ? root->val < bound : root->val > bound) 
        && isValid(root->left, bound, isLeft) 
        && isValid(root->right, bound, isLeft);
    }
    bool isValid2(TreeNode *root, TreeNode *&pre)
    {
        if (!root)
            return true;
        if (!isValid2(root->left, pre))
            return false;
        if (pre && root->val <= pre->val)
            return false;
        pre = root;
        return isValid2(root->right, pre);
    }
};
// @lc code=end
