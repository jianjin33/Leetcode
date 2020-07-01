/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 * 两个规律：
 * 1 cycle = 2n -2
 * 2 j + cycle - 2 * i = next; i = 0,1,2...
 */

// @lc code=start

#include <string>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int cycle = numRows * 2 - 2;

        if (cycle == 0 )
        {
            return s;
        }
        

        string result = "";
        for (size_t i = 0; i < numRows; i++)
        {
            // 处理每一行的字符
            for (size_t j = i; j < s.size(); j = j + cycle)
            {
                result = result + s[j];
                // int nextIndex = j + cycle - 2* i;
                int nextIndex = (j - i) + cycle - i;
                if (i != 0 && i != numRows - 1 && nextIndex < s.size())
                {
                    result = result + s[nextIndex];
                }
            }
        }
        return result;
    }
};
// @lc code=end
