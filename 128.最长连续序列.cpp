/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 * 
 * 解题思路： 通过map的value记录最大长度，以动态规划的思想，一次遍历统计出最大值
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int max = 0;
        unordered_map<int, int> map;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (!map[nums[i]]) // 非常重要的一步判断，若map中存在，一定不能再次进入计算
            {
                int lc = map[nums[i] - 1];
                int rc = map[nums[i] + 1];
                int sum = lc + rc + 1;
                map[nums[i]] = map[nums[i] - lc] = map[nums[i] + rc] = sum;
                max = std::max(sum, max);
            }
        }
        return max;
    }
};
// @lc code=end
