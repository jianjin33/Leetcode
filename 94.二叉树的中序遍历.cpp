/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 * 两种方式：递归和非递归
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
    void Inorder(vector<int> &nums, TreeNode *root)
    {
        if (root == NULL || root->val == NULL)
        {
            return;
        }
        Inorder(nums, root->left);
        nums.push_back(root->val);
        Inorder(nums, root->right);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> nums;
        // 递归方式
        // Inorder(nums, root);
        // 非递归方式
        stack<TreeNode *> todo;
        while (root || !todo.empty())
        {
            while (root)
            {
                todo.push(root);
                root = root->left;
            }

            root = todo.top();
            todo.pop();
            nums.push_back(root->val);
            root = root->right;
        }

        return nums;
    }
};
// @lc code=end
