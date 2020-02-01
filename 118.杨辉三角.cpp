/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    void InnerGenerate(vector<vector<int>> result, int rows, int numRows)
    {
        if (rows > numRows)
            return;
        
    }

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        vector<int> item;

        for (size_t i = 0; i < numRows; i++)
        {
            item.push_back(1);
            for (int j = i - 1; j > 0; j--)
            {
                item[j] = item[j] + item[j - 1];
            }
            result.push_back(item);
        }
        return result;
    }
};
// @lc code=end
