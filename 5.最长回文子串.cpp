/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

#include <string>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        const int size = s.size();
        int maxStart = 0, maxLengh = 0;

        for (size_t i = 0; i < size;)
        {
            int start = i, end = i;

            while (end < size - 1 && s[end] == s[end + 1])
                end++;
            // 说明end之前都是重复字符串
            i = end + 1;
            while (start - 1 >= 0 && end + 1 < size && s[start-1] == s[end+1])
            {
                start--;
                end++;
            }

            if (maxLengh < end - start + 1)
            {
                maxLengh = end - start + 1;
                maxStart = start;
            }
        }
        return s.substr(maxStart, maxLengh);
    }
};
// @lc code=end
