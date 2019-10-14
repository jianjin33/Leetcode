/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if (s.empty())
        {
            return 0;
        }

        unordered_map<char,int> map {{'I', 1}, {'V', 5}, {'X', 10},
         {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int sum = map[s.back()];
         for (int i = s.size() - 2; i >= 0; i--)
         {
            // 判断左边代表的数是否大于右边，大于则相加，小于则向减
             sum += map[s[i]] >= map[s[i + 1]] ? map[s[i]] : -map[s[i]];
         }
         
        return sum;

    }
};

