/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m =haystack.size();
        int n = needle.size();
        if (!n)
            return 0;
        
        for (int i = 0; i <= m - n; i++)
        {
            int temp = n;
            if (needle[0] == haystack[i])
            {
                int index = 0;
                while (temp--)
                {
                    if (needle[index] == haystack[index + i])
                    {
                        if (temp == 0)
                            return i;
                        index++;
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
