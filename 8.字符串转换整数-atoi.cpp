/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <limits.h>

class Solution
{
public:
    int myAtoi(std::string str)
    {
        long result = 0;
        int indicator = 1;
        for (int i = 0; i < str.size();)
        {
            //i = str.find_first_not_of(' '); // 这种方式找第一个，如果全是空的字符串，会溢出报错
            if(str[i] == ' '){
                i++;
                continue;
            }
            if (str[i] == '-' || str[i] == '+')
                indicator = (str[i++] == '-') ? -1 : 1;

            while ('0' <= str[i] && str[i] <= '9')
            {
                result = result * 10 + (str[i++] - '0');
                if (result * indicator >= INT_MAX)
                    return INT_MAX;
                if (result * indicator <= INT_MIN)
                    return INT_MIN;
            }
            return result * indicator;
        }

        return 0;
    }
};
// @lc code=end
