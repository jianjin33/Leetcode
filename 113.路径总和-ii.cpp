/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    std::vector<std::vector<int>> pathSum(TreeNode *root, int sum)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        int pathValue = 0;

        preorder(root, sum, pathValue, path, result);
        return result;
    }

    void preorder(TreeNode *root, int sum, int &pathValue, std::vector<int> &path, std::vector<std::vector<int>> &result)
    {
        if (!root)
        {
            return;
        }

        pathValue += root->val;
        path.push_back(root->val);

        if (pathValue == sum && !root->left && !root->right)
        {
            result.push_back(path);
        }

        preorder(root->left, sum, pathValue, path, result);
        preorder(root->right, sum, pathValue, path, result);

        pathValue -= root->val;
        path.pop_back();
    }
};
// @lc code=end
