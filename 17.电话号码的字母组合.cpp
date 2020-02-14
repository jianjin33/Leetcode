/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 * 回溯，选它会怎么样，不选它又会怎么样
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{

private:
    void BuildDict(unordered_map<char, vector<char>> &dict)
    {
        dict['2'] = vector{'a', 'b', 'c'};
        dict['3'] = vector{'d', 'e', 'f'};
        dict['4'] = vector{'g', 'h', 'i'};
        dict['5'] = vector{'j', 'k', 'l'};
        dict['6'] = vector{'m', 'n', 'o'};
        dict['7'] = vector{'p', 'q', 'r', 's'};
        dict['8'] = vector{'t', 'u', 'v'};
        dict['9'] = vector{'w', 'x', 'y', 'z'};
    }

    void Combine(int index, string digits, vector<string> &result, string &item, unordered_map<char, vector<char>> dict)
    {
        if (index == digits.size())
        {
            result.push_back(item);
            return;
        }

        vector<char> cur = dict[digits[index]];
        for (int i = 0; i < cur.size(); i++)
        {
            // 回溯思想
            // item.push_back(cur[i]);
            // Combine(index + 1, digits, result, item, dict);
            // item.pop_back();
            item[index] = cur[i];
            Combine(index + 1, digits, result, item, dict);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.empty())
            return result;

        unordered_map<char, vector<char>> dict;
        BuildDict(dict); // 构建键盘字典

        string item(digits.size(), ' ');
        Combine(0, digits, result, item, dict); // 开始进行组合
        return result;
    }
};
// @lc code=end
