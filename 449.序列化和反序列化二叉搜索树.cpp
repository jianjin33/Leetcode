/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
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
#include <string>
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

class Codec
{
public:
    // Encodes a tree to a single string.
    void transform2string(string &s, int val)
    {
        string temp;
        while (val)
        {
            temp += val % 10 + '0';
            val /= 10;
        }

        for (size_t i = 0; i < temp.length() - 1; i++)
        {
            s += temp[i];
        }
        s += '#';
    }

    string serialize(TreeNode *root)
    {
        // 前序遍历
        stack<TreeNode *> todo;
        string result;
        if (!root)
            return result;

        todo.push(root);
        while (!todo.empty())
        {
            root = todo.top();
            todo.pop();
            string str;
            transform2string(str, root->val);
            result.append(str);

            if (root->right)
                todo.push(root->right);
            if (root->left)
                todo.push(root->left);
        }

        return result;
    }

    // Decodes your encoded data to tree.
    void BSTInsert(TreeNode *root, TreeNode *node)
    {
        if (root->val > node->val)
        {
            if (root->right)
                BSTInsert(root->right, node);
            else
                root->right = node;
        }else
        {
            if (root->left)
                BSTInsert(root->left, node);
            else
                root->left = node;
        }
        
    }

    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return NULL;
        }
        vector<TreeNode *> vec;
        int val = 0;
        for (size_t i = 0; i < data.size(); i++)
        {
            if (data[i] == '#')
            {
                vec.push_back(new TreeNode(val));
            }
            else
            {
                val = val * 10 + data[i] - '0';
            }
        }

        for (size_t i = 0; i < vec.size(); i++)
        {
            BSTInsert(vec[0], vec[i]);
        }

        return vec[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
