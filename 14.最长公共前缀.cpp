/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        sort(strs.begin(), strs.end());
        
        string a = strs[0], b = strs.back();
        int i = 0,len =min(a.length(),b.length());
        for (; i < len; i++)
        {
            if (a[i] != b[i])
            {
                break;
            }
        }
        return a.substr(0,i);
    }
};
// @lc code=end
