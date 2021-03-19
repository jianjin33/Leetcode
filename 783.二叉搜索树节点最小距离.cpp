/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* pre = NULL;
        DFS(root, pre, minDiff);
        return minDiff;
    }
    
    void DFS(TreeNode* root, TreeNode*& pre, int& minDiff){
        if(!root) return;
        DFS(root->left, pre, minDiff);
        if(pre) minDiff = min(minDiff, abs(root->val - pre->val));
        pre = root;
        DFS(root->right, pre, minDiff);
    }
};
// @lc code=end

