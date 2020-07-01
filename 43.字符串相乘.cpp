/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int m = num1.size() - 1, n = num2.size() - 1, carry = 0;
        string result;
        for (int i = 0; i <= m + n || carry; i++)
        {
            for (int j = max(0, i - n); j <= min(i, m); j++)
            {
                carry += (num1[m - j] - '0') * (num2[n - i + j] - '0');
            }
            result += carry % 10 + '0';
            carry /= 10;
        }
        reverse(begin(result), end(result));
        return result;
    }
};
// @lc code=end
