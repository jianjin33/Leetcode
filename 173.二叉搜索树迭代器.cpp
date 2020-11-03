/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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

/* struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 */
class BSTIterator
{
    stack<TreeNode *> todo;

public:
    BSTIterator(TreeNode *root)
    {
        addAll(root);
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *temp = todo.top();
        todo.pop();
        addAll(temp->right);
        return temp->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !todo.empty();
    }

private:
    void addAll(TreeNode *root)
    {
        for (; root != nullptr; todo.push(root), root = root->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
