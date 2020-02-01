/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 * 用大顶堆和小顶堆来实现，
 * 还有其他实现方式 待研究
 * 
 * 提交不能通过问题：答案是一样的，浮点的位数不一致
 */

// @lc code=start
#include <queue>
#include <vector>

using namespace std;

class MedianFinder
{
public:
    priority_queue<int, vector<int>, greater<int>> smallQueue;
    priority_queue<int, vector<int>, less<int>> bigQueue;

    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (smallQueue.empty())
        {
            smallQueue.push(num);
            return;
        }

        /*        if (num > smallQueue.top())
            smallQueue.push(num);
        else
            bigQueue.push(num);

        if (!bigQueue.empty() && bigQueue.size() - smallQueue.size() > 1)
        {
            smallQueue.push(bigQueue.top());
            bigQueue.pop();
        }

        if (smallQueue.size() - bigQueue.size() > 1)
        {
            bigQueue.push(smallQueue.top());
            smallQueue.pop();
        } */

        if (smallQueue.size() > bigQueue.size())
        {
            if (num > smallQueue.top())
            {
                bigQueue.push(smallQueue.top());
                smallQueue.pop();
                smallQueue.push(num);
            }
            else
            {
                bigQueue.push(num);
            }
        }
        else if (smallQueue.size() < bigQueue.size())
        {
            if (num < smallQueue.top())
            {
                smallQueue.push(bigQueue.top());
                bigQueue.pop();
                bigQueue.push(num);
            }
            else
            {
                smallQueue.push(num);
            }
        }
        else
        {
            if (num < smallQueue.top())
            {
                bigQueue.push(num);
            }
            else
            {
                smallQueue.push(num);
            }
        }
    }

    double findMedian()
    {
        int diff = smallQueue.size() - bigQueue.size();
        if (diff > 0)
        {
            return smallQueue.top();
        }
        else if (diff < 0)
        {
            return bigQueue.top();
        }
        else
        {
            return static_cast<double>(smallQueue.top() + bigQueue.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
