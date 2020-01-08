/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int begin = 0, end = -1;
        for (size_t i = 0; i < s.size(); i++)
        {
            int l = 0, r = 0;
            if (s[i] == ' ')
            {
                if (i == 0 || i == 1)
                {
                    end = i - 1;
                    continue;
                }
                if (end != -1)
                    begin = end + 2;
                end = i - 1;
                l = begin;
                r = end;
            }

            if (i == s.size() - 1)
            {
                if (end != -1)
                    begin = end + 2;
                end = s.size() - 1;
                l = begin;
                r = end;
            }

            while (l < r)
            {
                swap(s[l++], s[r--]);
            }
        }
        return s;
    }
};
// @lc code=end
