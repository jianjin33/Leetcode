/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    void internalPermute(vector<int> &nums,
                         vector<vector<int>> &result,
                         int pos)
    {
        if (pos == nums.size() - 1)
        {
            result.push_back(nums);
            return;
        }

        for (size_t i = pos; i < nums.size(); i++)
        {
            if (i != pos && nums[i] == nums[pos])
            {
                continue;
            }

            swap(nums[i], nums[pos]);
            internalPermute(nums, result, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        internalPermute(nums, result, 0);
        return result;
    }
};
// @lc code=end
