/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 * 第几行就有几个硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int raw = 0;
       while (n > raw)
       {
           raw++;
           n -= raw;
       }
       
        return raw;
    }
};
// @lc code=end

