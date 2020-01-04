/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int begin = 0, end = nums.size() - 1;

        vector<int> result;
        while (begin <= end)
        {
            int mid = (end + begin) / 2;
            if (target == nums[mid])
            {
                int temp = mid;
                // 判断右边是否到达最右边
                while (temp > 0 && nums[temp - 1] == target)
                {
                    temp--;
                }
                result.push_back(temp);

                // 左边
                temp = mid;
                while (temp < nums.size() - 1 && nums[temp + 1] == target)
                {
                    temp++;
                }
                result.push_back(temp);
                break; //跳出循环
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                begin = mid + 1;
            }
        }
        if (result.empty())
        {
            result.push_back(-1);
            result.push_back(-1);
        }
        

        return result;
    }
};
// @lc code=end
