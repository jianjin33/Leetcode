/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * 回溯算法
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    void InternalGenerate(string sublist, vector<string> &v, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            // 左右括号都用尽，则加入集合 并结束
            v.push_back(sublist);
            return;
        }
        // 条件 左括号没有用完（才可以加左括号）
        // 右括号数目小于左括号数目（才可以加右括号）
        if (left > 0)
            InternalGenerate(sublist + "(", v, left--, right);
        if (right > left)
            InternalGenerate(sublist + ")", v, left, right--);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> v;

        InternalGenerate("", v,n, n);

        for (size_t i = 0; i < v.size(); i++)
        {
            cout << "输出" << v[i] << endl;
        }
        return v;
    }
};
// @lc code=end
