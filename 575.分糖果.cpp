/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 * 思路：
 * 算出一共多少个种类
 * 总个数／2 大于 种类数 结果就是 总数／2
 *          小于 结果就是 种类数
 */

// @lc code=start

#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    
    int distributeCandies(vector<int> &candies)
    {
        unordered_map<int, int> map;
        int length = candies.size();
        for (auto candy : candies)
        {
            map[candy]++;
        }
        int count = map.size() >= length / 2 ? length / 2 : map.size();
        return count;
    }
};
// @lc code=end
