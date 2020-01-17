/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int result = 0;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            int h = std::min(height[i], height[j]);
            result = std::max(result, h * (j - i));

            while (i < j && height[i] <= h)
            {
                i++;
            }
            while (i < j && height[j] <= h)
            {
                j--;
            }
        }

        return result;
    }
};
// @lc code=end
