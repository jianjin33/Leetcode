/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {

        if (nums.empty())
        {
            return 0;
        }
        
        vector<int> tempDp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                tempDp[i] = nums[0];
                continue;
            }
            if (i == 1)
            {
                tempDp[i] = max(nums[0], nums[1]);
                continue;
            }

            tempDp[i] = max(nums[i] + tempDp[i - 2], tempDp[i - 1]);
        }

        return tempDp[nums.size() - 1];
    }
};
// @lc code=end
