/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size() - 1;
        int len = 0;
        // if (n < 0)
        //     return 0;

        // for (size_t i = n; i >= 0; i--)
        // {
        //     if (s[i] == ' ')
        //         break;
        //     len++;
        // }
        while (n >= 0 && s[n] == ' ') n--;
        while (n >= 0 && s[n] != ' ') {
            len++;
            n--;
        }
        return len;
    }
};
// @lc code=end
