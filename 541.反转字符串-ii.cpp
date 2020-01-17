/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
#include <string>

class Solution
{
public:
    std::string reverseStr(std::string s, int k)
    {

        // int begin = 0, end = 0;
        // int size = s.size();
        // int count = size / (2 * k) + 1;

        // for (size_t i = 0; i < count; i++)
        // {
        //     begin = i * 2 * k;
        //     end = begin + k - 1;
        //     if (end >= size)
        //     {
        //         end = size - 1;
        //     }
        //     while (begin <= end)
        //     {
        //         std::swap(s[begin], s[end]);
        //         begin++;
        //         end--;
        //     }
        // }
        // 提交也可以通过

        if(s=="")
            return "";
        
        for(int i=0;i<s.size()-1;i++)
        {
            if(i%(2*k)==0)
            {
                if((k+i)>s.size())
                    reverse(s.begin()+i,s.end());
                else
                    reverse(s.begin()+i,s.begin()+k+i);
            }
        }

        return s;
    }
};
// @lc code=end
