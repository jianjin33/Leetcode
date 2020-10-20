/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 * 
 * 动态规划，通过从底部往上的方式去获取最小值，不能从上往下去遍历是因为即使确定了下一层的最小路径后 也不能确定下下层是大还是小
 * 而从下往上可以确定每个路径的最小值，直到顶点
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // C++基础：这里的for循环为什么不能用size_t
        // 不能用size_t，因为它是unsigned int，当triangle.size() - 2为-1时，实际上是赋给i一个很大的值
        for (int i = triangle.size() - 2; i >= 0; --i)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};
// @lc code=end

