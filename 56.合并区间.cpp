/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a.front() < b.front();
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        if (intervals.empty())
            return result;

        sort(intervals.begin(), intervals.end(), compare);
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].front() <= result.back().back())
            {
                vector<int> temp;
                temp.push_back(min(intervals[i].front(), result.back().front()));
                temp.push_back(max(intervals[i].back(), result.back().back()));
                result.pop_back();
                result.push_back(temp);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
// @lc code=end
