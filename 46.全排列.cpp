/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <vector>

using namespace std;

// @lc code=start
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
            swap(nums[i], nums[pos]);
            internalPermute(nums, result, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        internalPermute(nums, result, 0);
        return result;
    }
};
// @lc code=end
