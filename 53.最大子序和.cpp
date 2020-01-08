/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 * 思路：动态规划
 * 遍历的节点，如果前一个节点向关的最大值大于0 则带上前面，小于0 就从该节点开始重新计算
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        int begin = 0, end = 1;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int tempMax = dp[0];

        for (size_t i = 1; i < nums.size(); i++)
        {
            if (dp[i - 1] < 0)
            {
                begin = i;
                dp[i] = nums[i];
            }else
            {
                dp[i] = nums[i] + dp[i - 1];
            }
            
            if (tempMax < dp[i])
            {
                end = i;
                tempMax = dp[i];
            }
            
        }
        return tempMax;
    }
};
// @lc code=end
