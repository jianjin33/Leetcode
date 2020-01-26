/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        bool insert = true;

        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (!insert)
                break;
            digits[i] = (digits[i] + 1) % 10;
            insert = digits[i] == 0;
        }

        // 进一位
        if (insert)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};
// @lc code=end
