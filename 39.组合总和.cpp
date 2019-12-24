/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 * 回溯算法
 * 思路：target － arr[i] 大于0 ，target改为相差值，继续递归这个差值的。
 * 过程中巧妙用到vector，pop_back(),调用之前，条件符合会加入到result中
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    void Find(vector<vector<int>> &result, vector<int> &item, vector<int> &candidates,
              int target, int next)
    {
        // 目标数 与当前指定值相同或相差为0，满足条件 结束
        // target 大于 当前指定值，不符合 跳过
        // target 小于 当前指定值，获得差值，继续找

        if (target == 0)
        {
            result.push_back(item);
            return;
        }

        if (next > candidates.size() - 1 || target - candidates[next] < 0)
        {
            return;
        }

        item.push_back(candidates[next]);
        Find(result, item, candidates, target - candidates[next], next);
        item.pop_back();

        Find(result, item, candidates, target, next + 1);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> item;
        sort(candidates.begin(),candidates.end());
        Find(res, item, candidates, target, 0);
        return res;
    }
};
// @lc code=end
