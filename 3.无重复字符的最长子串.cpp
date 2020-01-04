/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 * map key 存字符，value存索引，一旦有重复，去value值作为开始索引
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        /*  if (s.empty())
            return 0;

        int startIndex = -1, maxLength = 0;
        std::unordered_map<char, int> map;

        for (int i = 0; i != s.length(); i++)
        {
            if (map[s[i]] >= 0)
            {
                if (i != 0);
                {
                    startIndex = map[s[i]];
                }
            }
            map[s[i]] = i;
            maxLength = std::max(i - startIndex, maxLength);
        }
        return maxLength; */
        std::vector<int> dict(255, -1);
        int startIndex = -1, maxLength = 0;
        for (int i = 0; i != s.length(); i++)
        {
            if (dict[s[i]] > startIndex)
            {
                startIndex = dict[s[i]];
            }
            dict[s[i]] = i;
            maxLength = std::max(i - startIndex, maxLength);
        }
        return maxLength;
    }
};
// @lc code=end
