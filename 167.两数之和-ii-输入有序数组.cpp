/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0, j = numbers.size() - 1;
        vector<int> result;
        while (i < j)
        {
            int sum = numbers[i] + numbers[j];
            if (sum == target)
            {
                result.push_back(i + 1);
                result.push_back(j + 1);
                return result;
            } else if (sum > target)
            {
                j--;
            }else
            {
                i++;
            }
        }
        return result;
    }
};
// @lc code=end
