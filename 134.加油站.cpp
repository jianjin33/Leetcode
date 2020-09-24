/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start(0), subsum(INT_MAX), total(0);
        for (size_t i = 0; i < gas.size(); i++)
        {
            total += gas[i] - cost[i];
            if (total < subsum)
            {
                subsum = total;
                start = i + 1;
            }
        }
        return total < 0 ? -1 : start % gas.size();

    }
};
// @lc code=end

