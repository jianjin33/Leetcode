/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 * 贪心
 * 思路：遍历一排孩子，
 * 到第一个孩子 假设最小，给一个糖，
 * 到第二个孩子 与前一个比，
 *      大于 则在前一个个数基础上 ＋1个糖
 *      小于 则在前一个个数基础上 －1个糖 若－1之后为0则特殊处理，前面每个孩子各加一个糖
 *      相等 分1一个糖。 这里就有个问题。可以说相等之后，可以分段处理，之前的算是分完了
 * 以上思路有漏洞 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int count = 0;
        int splitIndex = 0;
        int lastCount = 0;
        for (size_t i = 0; i < ratings.size(); i++)
        {
            int x = 0;
            if (i == 0)
            {
                x = 1;
            }
            else
            {
                if (ratings[i] > ratings[i - 1])
                {
                    x = lastCount + 1;
                }
                else if (ratings[i] < ratings[i - 1])
                {
                    x = lastCount - 1;
                    if (x == 0)
                    {
                        x = 1;
                        count += (i - splitIndex);
                    }
                    if (i == ratings.size() - 1)
                    {
                        x = 1;
                    }
                    
                }else
                {
                    x = 1;
                    // 重新开始计算
                    splitIndex = i;
                }
                
            }

            lastCount = x;
            count += x;
        }
        return count;
    }

};
// @lc code=end
