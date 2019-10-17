/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <unordered_map>
 
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            // 2.找到当前索引值相加的另一个值，作为key去查找，如果值存在，取value（即找到索引）
            if (map.find(target - nums[i]) != map.end())
            {
                return {map[target - nums[i]], i};
            }
            // 1.map的key是值，value是索引
            map[nums[i]] = i;
        }
        return {};
    }
};

