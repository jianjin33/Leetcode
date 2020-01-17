
/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 * 思路：每个数都对应有个状态，（较前一个数的状态，升，降，或一样）
 * 迭代 到每一个数，拿到前一个数的状态，如果这个数的状态和上一个状态一样，则不做处理
 * 若状态相反，则＋1处理，说明符合要去
 * 
 * 引入一个状态机概念，更清晰
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        
        int i = 1;
        const int BEGIN = 0, UP = 1, DOWN = 2;
        int state = BEGIN;
        vector<int> result;
        result.push_back(nums[0]);
        while (i < nums.size())
        {
            switch (state)
            {
            case BEGIN:
                if (nums[i] > nums[i - 1])
                {
                    state = UP;
                    result.push_back(nums[i]);
                }
                else if (nums[i] < nums[i - 1])
                {
                    state = DOWN;
                    result.push_back(nums[i]);
                }
                break;
            case UP:
                if (nums[i] < nums[i - 1])   
                {
                    state = DOWN;
                    result.push_back(nums[i]);
                }
                break;
            case DOWN:
                if (nums[i] > nums[i - 1])
                {
                    state = UP;
                    result.push_back(nums[i]);
                }
                break;

            default:
                break;
            }
            i++;
        }

        return result.size();
    }
};
// @lc code=end
