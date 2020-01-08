/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *  回溯
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    void generate(vector<int> &nums, vector<vector<int>> &result, vector<int> item, int i)
    {
        if (i >= nums.size())
        {
            return;
        }

        item.push_back(nums[i]);
        result.push_back(item);
        generate(nums, result, item, i + 1);

        item.pop_back();
        generate(nums, result, item, i + 1);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> item;
        result.push_back(item); // 空子集特殊处理
        generate(nums, result, item, 0);
        return result;
    }
};
// @lc code=end
