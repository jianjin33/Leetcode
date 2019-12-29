/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 * 两个队列，一个是临时队列
 */

// @lc code=start

#include <queue>

using namespace std;

class MyStack
{
public:
    queue<int> tempQueue;
    queue<int> dataQueue;

    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        while (!dataQueue.empty())
        {
            tempQueue.push(dataQueue.front());
            dataQueue.pop();
        }

        dataQueue.push(x);

        while (!tempQueue.empty())
        {
            dataQueue.push(tempQueue.front());
            tempQueue.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {

        int x = dataQueue.front();
        dataQueue.pop();
        return x;
    }

    /** Get the top element. */
    int top()
    {
        return dataQueue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return dataQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
