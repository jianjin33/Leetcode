/*
 * @lc app=leetcode.cn id=1349 lang=cpp
 *
 * [1349] 参加考试的最大学生数
 * 思路：枚举法时间复杂度 2^m*n。动态规划 ＋ 状态压缩
 * 
 * 技巧1:
 * 如何判断两个1相邻？如 1010不相邻，1100有相邻。可通过 1100 & 1100 >> 1 == 0 判断；
 * 即1100 & 100 ＝ 0100 表明有1相邻；（可判断题中两座位不相邻）
 * 
 * 技巧2: 如何判断两数不会交叉出现1（即题中可看到斜前方的答案）
 * 如1010和1101 可通过 1010 >> 1 & 1101判断1010的右后方有么有1
 * 通过 1010 & 1101 >> 1 判断1010的左后方是否为1
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int maxStudents(vector<vector<char>> &seats)
    {
        const int m = seats.size();
        const int n = seats[0].size();

        vector<int> s(m + 1);

        // 标记不可以坐的座位 #:1  .:0
        for (int i = 1; i <= m; ++i)
            for (int j = 0; j < n; ++j)
                s[i] |= (seats[i - 1][j] == '#') << j;

        vector<vector<int>> dp(m + 1, vector<int>(1 << n));
        for (int i = 1; i <= m; i++)
        {
            for (int c = 0; c < (1 << n); c++)
            {
                if (c & c >> 1 || c & s[i]) // 座位相邻或者分配的座位不可坐是 跳过
                    continue;
                for (int l = 0; l < (1 << n); l++)
                    if (!(l & s[i - 1]) && !(l & (c >> 1)) && !(c & (l >> 1)))
                    {
                        dp[i][c] = max(dp[i][c], dp[i - 1][l] + __builtin_popcount(c));
                    }
            }
        }
        return *max_element(begin(dp[m]), end(dp[m]));
    }
};
// @lc code=end
