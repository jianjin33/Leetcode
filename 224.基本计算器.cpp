/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    int compute(stack<int> &numStack, stack<int> &opsStack)
    {
        int result = numStack.top();
        numStack.pop();
        if (opsStack.empty())
        {
            return result;
        }
        
        if (opsStack.top() == 1)
        {
            result += numStack.top();
        }
        else if (opsStack.top() == -1)
        {
            result -= numStack.top();
        }
        opsStack.pop();
        numStack.pop();
        return result;
    }

    int calculate(string s)
    {
        stack<int> numStack, opsStack;
        int sign = 0; // 计算的标识位
        int num = 0;
        const int BEGIN = 0;
        const int NUM = 1;
        const int OPTS = 2;
        int STATE = BEGIN;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
                continue;

            switch (STATE)
            {
            case BEGIN:
                if (s[i] >= '0' && s[i] <= '9')
                {
                    STATE = NUM;
                }
                else
                {
                    STATE = OPTS;
                }
                i--;
                break;

            case NUM:
                if (s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + s[i] - '0';
                }
                else
                {
                    numStack.push(num);
                    if (sign == 1)
                    {
                        compute(numStack, opsStack);
                    }

                    num = 0;
                    STATE = OPTS;
                    i--;
                }
                break;

            case OPTS:
                if (s[i] == '+')
                {
                    opsStack.push(1);
                    sign = 1;
                }
                else if (s[i] == '-')
                {
                    opsStack.push(-1);
                    sign = 1;
                }
                else if (s[i] == '(')
                {
                    STATE = NUM;
                    sign = 0;
                }
                else if (s[i] == ')')
                {
                    compute(numStack, opsStack);
                }
                else if (s[i] >= '0' && s[i] <= '9')
                {
                    STATE = NUM;
                    i--;
                }
                break;

            default:
                break;
            }
        }

        if (num != 0)
        {
            numStack.push(num);
            compute(numStack, opsStack);
        }

        if (num == 0 && numStack.empty())
        {
            return 0;
        }

        return numStack.top();
    }
};
// @lc code=end
