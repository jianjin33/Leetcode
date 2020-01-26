/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int num : nums)
        {
            if (i == 0 || num > nums[i - 1])
            {
                nums[i++] = num;
            }
        }
        return i;
    }
};
// @lc code=end
