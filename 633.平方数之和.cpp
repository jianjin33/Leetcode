/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 * 和167题一致，同属于双指针问题，只是多了一个开方的剪枝，
 */

// @lc code=start
#include <cmath>

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        unsigned int s = 0, e = std::sqrt(c);
        while (s <= e) // 当c＝2是 可以是1*1+1*1 所以条件是小于等于
        {
            int sum = s * s + e * e;
            if (sum == c)
            {
                return true;
            }
            else if (sum > c)
                e--;
            else
                s++;
        }

        return false;
    }
};
// @lc code=end
