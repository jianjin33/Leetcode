/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        // if (n == 1 || n == 2)
        //     return n;
        // return climbStairs(n - 1) + climbStairs(n - 2);
        // timeout 

         unsigned int result[n + 3]; // 加3是兼容 n ＝ 0 1问题
        // 有符号 45时 int会溢出 无符号是65535 刚好可以装下
         result[0] = 0;
         result[1] = 1;
         result[2] = 2;

         for (int i = 3; i < n + 3; i++)
         {
             result[i] = result[i - 1] + result[i - 2];
         }
         return result[n];
         
    }
};
// @lc code=end
