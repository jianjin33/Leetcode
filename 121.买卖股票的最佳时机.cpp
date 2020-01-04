/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxPro = 0;
        for (size_t i = 0; i < prices.size(); i++)
        {
            minPrice = std::min(minPrice, prices[i]);
            maxPro = std::max(maxPro,  prices[i] - minPrice);
        }
        return maxPro;
    }
};
// @lc code=end
