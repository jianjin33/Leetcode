/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 * 思路 维护一个最小值 栈，每次push比较是否最小，是则push其中，否则push一个上个最小值
 * 一定要保持两个栈的元素个数一样，这样top时好操作
 * 
 * peek top element
 * push add offer
 * pop  remove poll
 */

// @lc code=start

#include <stack>

class MinStack
{
public:
    std::stack<int> minStack;
    std::stack<int> dataStack;
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        dataStack.push(x);
        if (minStack.empty())
        {
            minStack.push(x);
        }
        else
        {
            minStack.push(minStack.top() >= x ? x : minStack.top());
        }
    }

    void pop()
    {
        dataStack.pop();
        minStack.pop();
    }

    int top()
    {
        return dataStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
