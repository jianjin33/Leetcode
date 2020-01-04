/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include <stack>
using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &nums)
    {
        if (!root)
        {
            return;
        }
        nums.push_back(root->val);

        preorder(root->left, nums);
        preorder(root->right, nums);
    }

    void preorder2(TreeNode *root, vector<int> &nums)
    {
        if (!root)
        {
            return;
        }

        stack<TreeNode *> todo;
        todo.push(root);
        while (!todo.empty())
        {

            root = todo.top();
            todo.pop();
            nums.push_back(root->val);
            if (root->right)
                todo.push(root->right);
            if (root->left)
                todo.push(root->left);
        }
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> nums;
        // 递归
        // preorder(root, nums);
        // 迭代
        preorder2(root, nums);
        return nums;
    }
};
// @lc code=end
