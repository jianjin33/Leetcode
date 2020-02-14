/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1, j = num2.size() - 1;

        int sum = 0;
        string result;

        // 第三个条件，是适配进位问题，比如 ：9 + 1 ＝ 10 应该再执行最后一遍，否则就是0
        while (i >= 0 || j >= 0 || sum)
        {
            if (i >= 0)
                sum += num1[i--] - '0';
            if (j >= 0)
                sum += num2[j--] - '0';
            result.append(to_string(sum % 10));
            sum /= 10;
        }

        reverse(result.begin(),result.end());
        return result;
    }
};
// @lc code=end
