/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    void findNodePath(TreeNode *root, TreeNode *target, vector<TreeNode *> &path, vector<TreeNode *> &result, int &finish)
    {
        if (!root || finish)
            return;

        path.push_back(root);
        if (root == target)
        {
            finish = 1;
            result = path;
        }
        findNodePath(root->left, target, path, result, finish);
        findNodePath(root->right, target, path, result, finish);
        path.pop_back();
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path;


        vector<TreeNode *> pPath;
        int pResult = 0;
        findNodePath(root, p, path, pPath, pResult);

        vector<TreeNode *> qPath;
        int qResult = 0;
        path.clear();
        findNodePath(root, p, path, qPath, qResult);

        int shortSize = min(pPath.size(), qPath.size());

        TreeNode *result;
        for (int i = 0; i < shortSize; i++)
        {
            if (pPath[i] == qPath[i])
                result = qPath[i];
        }
        return result;
    }
};
// @lc code=end
