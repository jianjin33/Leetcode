/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int result = 0;
        int sum = divisor;
        while (dividend > sum)
        {
            sum += divisor;
            result++;
        }
        return result;
    }
};
// @lc code=end
