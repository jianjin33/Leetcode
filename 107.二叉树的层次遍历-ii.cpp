/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        // 层次遍历法 20 ms
        // if (!root)
        //     return result;

        // vector<int> item;

        // queue<TreeNode *> todo;
        // todo.push(root);

        // while (!todo.empty())
        // {
        //     int count = todo.size();
        //     item.clear();
        //     for (size_t i = 0; i < count; i++)
        //     {
        //         TreeNode *node = todo.front();
        //         todo.pop();

        //         item.push_back(node->val);
        //         if (node->left)
        //             todo.push(node->left);
        //         if (node->right)
        //             todo.push(node->right);
        //     }
        //     result.insert(result.begin(), item);
        // }

        // 方法二：递归法 8 ms
        levelOrder(result, root, 0);
        reverse(result.begin(), result.end());
        return result;
    }

    void levelOrder(vector<vector<int>> &result, TreeNode *node, int level)
    {
        if (!node)
            return;
        if (level >= result.size())
            result.push_back({});

        result[level].push_back(node->val);
        levelOrder(result, node->left, level + 1);
        levelOrder(result, node->right, level + 1);
    }
};
// @lc code=end
