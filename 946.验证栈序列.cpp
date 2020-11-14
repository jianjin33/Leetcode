/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 * 
 * 堆栈结合，通过相同则弹出操作，秒啊
 */

// @lc code=start
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        queue<int> q;
        queue<int> qt;
        stack<int> s;
        for (size_t i = 0; i < popped.size(); i++)
        {
            q.push(popped[i]);
            qt.push(pushed[i]);
        }

        while (!qt.empty())
        {
            s.push(qt.front());
            qt.pop();
            while (!s.empty() && s.top() == q.front())
            {
                s.pop();
                q.pop();
            }
        }

        return s.empty();
    }
};
// @lc code=end
