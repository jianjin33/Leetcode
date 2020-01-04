/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        queue<TreeNode *> q;

        if (!root)
        {
            return result;
        }
        
        q.push(root);

        while (!q.empty())
        {
            result.push_back(q.back()->val);

            int size = q.size();
            for (size_t i = 0; i < size; i++)
            {
                TreeNode * node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                
            }
            
        }

        return result;
    }
};
// @lc code=end
