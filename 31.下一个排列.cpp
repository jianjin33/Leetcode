/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 * 解决思路：从后向前遍历，
 * 未发现： k > k-1，reverse即可
 * 发现： 将k-1的数分别与k之后的数值进行比较，因为此时k之后的都是一定是降序排列，一旦发现[l] > [k-1]进行reverse
 * 此时0～k-1的数已经确定，保证了次大数，k之后的降序reverse变升序就是最终结果
 * 
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int size = nums.size(), l, k;
        if (nums.empty() || size == 1)
            return;

        for (k = size - 1; k >= 1; k--)
        {
            if (nums[k] > nums[k - 1])
                break;
        }

        if (k == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (l = size - 1; l > k; l--)
        {
            if (nums[l] > nums[k - 1])
            {
                break;
            }
        }
        swap(nums[l], nums[k - 1]);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end
