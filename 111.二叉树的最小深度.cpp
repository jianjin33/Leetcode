/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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

#include <algorithm>


class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        // 1. root为空则结束
        if (root == nullptr)
            return 0;
        // root若为最底部节点，left和right都为空，则走到上面第一步，返回0
        int L = minDepth(root->left), R = minDepth(root->right);
        // 2. 如果左右都不为0（不为空），则比较左右两个哪个最小；如果是最底部节点，都为0；若果其中一个为null
        // 另一个不为null，则需要取另一个的层级，所以取最大值（一个为0，另一个可能是1,2,3）
        // 3. 最后一个节点走到这里会+1返回上一层递归中去。
        return 1 + ((L && R) ? std::min(L, R) : std::max(L, R));
    }
};
// @lc code=end
