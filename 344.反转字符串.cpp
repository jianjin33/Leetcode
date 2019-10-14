/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include <vector>
#include <utility>


class Solution {
public:
    void reverseString(std::vector<char>& s) {
        // 直接暴力翻转即可，没有投机取巧的方式
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            std::swap(s[i++], s[j--]);
        }
    }
};

