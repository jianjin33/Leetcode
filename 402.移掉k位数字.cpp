/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 * 贪心算法 高位数贪小数字
 * 思路：从高位开始，高位与低位相比，小就保留 大就移除，直到移除k个
 * 比如123...，移除1，剩下都是2开头的数，肯定不是最小，所以1一定要保留
 * 要考虑两个问题，数字都相同；有0的存在
 * 
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        vector<int> remain;
        string s = "";

        for (size_t i = 0; i < num.size(); i++)
        {
            int x = num[i] - '0';
            while (remain.size() > 0 && remain[remain.size() - 1] > x && k > 0)
            {
                remain.pop_back();
                k--;
            }
            if (x != 0 || remain.size() != 0)
            {
                remain.push_back(x);
            }
        }

        // 依旧可以删除数字
        while (remain.size() != 0 && k > 0)
        {
            remain.pop_back();
            k--;
        }

        if (remain.size() == 0)
        {
            return "0";
        }

        for (int c : remain)
        {
            s.append(1, '0' + c);
        }
        
        return s;
    }
};
// @lc code=end
