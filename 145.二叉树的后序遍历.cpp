/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include <stack>
#include <vector>

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
private:
    void Postorder(TreeNode *root, vector<int> &nodes)
    {
        if (!root || root->val == NULL)
        {
            return;
        }

        Postorder(root->left, nodes);
        Postorder(root->right, nodes);
        nodes.push_back(root->val);
    }

    void Postorder2(TreeNode *root, vector<int> &nodes)
    {
        stack<TreeNode *> todo;
        TreeNode *last = NULL;
        while (root || !todo.empty())
        {
            while (root)
            {
                todo.push(root);
                root = root->left;
            }

            TreeNode *cur = todo.top();
            // 当前结点右子结点不为空 并写没有访问
            if (cur->right && cur->right != last)
            {
                root = cur->right;
            }else
            {
                nodes.push_back(cur->val);
                todo.pop();
                last = cur; // 加入了vector之后记录该结点
            }
            
        }
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> nodes;
        // 递归遍历
        // Postorder(root, nodes);
        // 非递归遍历
        Postorder2(root, nodes);

        return nodes;
    }
};
// @lc code=end
