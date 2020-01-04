/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1, index = -1;
        while (index == -1)
        {
            int mid = (start + end) / 2;

            if (nums[mid] == target)
            {
                index = mid;
            }
            else if (nums[mid] > target)
            {
                if (mid == 0 || target > nums[mid - 1])
                {
                    index = mid;
                }

                end = mid - 1;
            }
            else
            {
                if (mid == nums.size() - 1 || target < nums[mid + 1])
                {
                    index = mid + 1;
                }
                start = mid + 1;
            }
        }
        return index;
    }
};
// @lc code=end
