/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 * 
 * 3中方法：1.和第20题一样使用栈的方式。2.动态规划。3.借助变量的方式（来回左右的遍历一遍）
 * 思路一：栈的方式是记录一个下标索引，一旦有最大值就记录下来
 * 思路二：动态规划dp数组记录的为当前索引对应的最长有效长度
 * 思路三：遍历统计左右数量，对于合法，左右数量一定相同，不同则置0，继续＋＋
 */

// @lc code=start

#include <string>
#include <stack>
#include <algorithm>
#include <vector>

class Solution
{
public:
    int longestValidParentheses(std::string s)
    {
        int longestValid = 0;
        // 第一种方案 通过
        // std::stack<int> temp;
        // temp.push(-1); // 处理临界条件
        // for (int i = 0; i < s.size(); i++)
        // {
        //     if (s[i] == ')' && temp.size() >= 2 && s[temp.top()] == '(')
        //     {
        //         temp.pop();
        //         int last = i - temp.top();
        //         longestValid = std::max(longestValid, last);
        //     }
        //     else
        //     {
        //         temp.push(i);
        //     }
        // }

        // 第二种方案 通过 画图理解
        // int size = s.size();
        // std::vector<int> dp(size, 0);
        // for (int i = 1; i < size; i++)
        // {
        //     if (s[i] == ')')
        //     {
        //         if (s[i - 1] == '(') // (())() 最后一个括号）时
        //         {
        //             dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        //         }
        //         else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') // (())时候
        //         {
        //             dp[i] = dp[i - 1] + 2;
        //             if (i - dp[i - 1] - 2 >= 0) // ()(()) 最后一个括号）时
        //             {
        //                 dp[i] += dp[i - dp[i - 1] - 2];
        //             }
        //         }
        //     }
        //     longestValid = std::max(dp[i], longestValid);
        // }

        int left = 0, right = 0;
        for (size_t i = 0; i != s.size(); i++)
        {
            if (s[i] == '(')
                left++;
            else
                right++;

            // 正向遍历 所以运行left>right 如(()) 但是))((就是非法的
            if (left == right)
            {
                longestValid = std::max(longestValid, 2 * right);
            }
            else if (left < right)
            {
                left = right = 0;
            }
        }

        left = right = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right)
            {
                longestValid = std::max(longestValid, 2 * right);
            }
            else if (left > right) // 反向这里不同
            {
                left = right = 0;
            }
        }

        return longestValid;
    }
};
// @lc code=end
