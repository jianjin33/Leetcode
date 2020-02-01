/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 * 思路：深搜 递归 返回值为 node ＋ 左和右中的最大值，
 * root左右 如果小于0 则不带，结果为当前最临时结果 或 左＋右＋node的值的最大值
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
private:
    int DFS(TreeNode *node, int &result)
    {
        if (!node)
            return 0;
        int l = std::max(0, DFS(node->left, result));
        int r = std::max(0, DFS(node->right, result));

        result = std::max(result, l + r + node->val);
        return std::max(l, r) + node->val;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int result = INT_MIN;
        DFS(root, result);
        return result;
    }
};
// @lc code=end
