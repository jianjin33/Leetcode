/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>

using namespace std;

class Solution
{
public:
    // vector<vector<int>> combine(int n, int k)
    // {
    //     vector<vector<int>> res;
    //     backtrack(res, n, k, vector<int>());
    //     return res;
    // }

    // void backtrack(vector<vector<int>> &res, int n, int k, vector<int> comb)
    // {
    //     if (k == 0)
    //     {
    //         res.push_back(comb);
    //         return;
    //     }
    //     if (n > k)
    //         backtrack(res, n - 1, k, comb);
    //     comb.push_back(n);
    //     backtrack(res, n - 1, k - 1, comb);
    // }
    void InternalCombine(int count, int n, int k, vector<vector<int>> &result, vector<int> &item)
    {

        if (item.size() == k)
        {
            result.push_back(item);
            return;
        }

        if (count < n)
        {
            item.push_back(count);
            InternalCombine(count + 1, n, k, result, item);
            item.pop_back();
            InternalCombine(count + 1, n, k, result, item);
        }
    }

    vector<vector<int>>
    combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> item;
        InternalCombine(1, n + 1, k, result, item);
        return result;
    }
};
