/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <stack>

class MyQueue
{
public:
    std::stack<int> tempStack;
    std::stack<int> dataStack;

    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        dataStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int x = peek();
        tempStack.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        if (tempStack.empty())
        {
            while (!dataStack.empty())
            {
                tempStack.push(dataStack.top());
                dataStack.pop();
            }
        }
        return tempStack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return dataStack.empty() && tempStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
