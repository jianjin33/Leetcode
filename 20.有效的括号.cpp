/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start

#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> pool;
        for (char c : s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                pool.push(c);
                break;
            case ')':
                if (pool.empty() || pool.top() != '(')
                {
                    return false;
                }
                else
                {
                    pool.pop();
                     break;
                }
            case ']':
                 if (pool.empty() || pool.top() != '[')
                {
                    return false;
                }
                else
                {
                    pool.pop();
                    break;
                }
            case '}':
                  if (pool.empty() || pool.top() != '{')
                {
                    return false;
                }
                else
                {
                    pool.pop();
                     break;
                }
            default:
                break;
            }
        }

        return pool.empty() ;
    }
};
// @lc code=end
