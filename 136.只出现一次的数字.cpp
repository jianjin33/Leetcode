/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 * 
 * 位运算 异或^ 相同则0 不同则1
 * 相同的数字经过异或运算后结果为0，
 * 除单独出现一次的数字外，其他数字都是出现两次的，
 * 那么这些数字经过异或运算后结果一定是0。
 * 而任何数字与0进行异或运算都是该数字本身。
 * 所以对数组所有元素进行异或运算，运算结果就是题目的答案。
 */
#include <vector>
#include<set>

using namespace std;

class Solution 
{
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            result = result ^ nums[i];
        }
        return result;
    }

    /**
     * 比较暴力的解决方式
     */
    int singleNumber2(vector<int>& nums) 
    {
        set<int> set;
        if(nums.empty()) return 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if(set.find(nums[i]) != set.end())
            {
                set.erase(nums[i]);
            } else
            {
                set.insert(nums[i]);
            }
        }
        return *set.begin();
    }
};

