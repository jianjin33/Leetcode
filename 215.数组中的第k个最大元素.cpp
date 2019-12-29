/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 * 使用优先队列，java的相关类为PriorityQueue或PriorityBlockingQueue
 * 默认升序，可以在初始化传入Comparator接口实现，来控制升降序
 * 
 * 升序队列
 * priority_queue <int,vector<int>,greater<int> > q;
 * 降序队列 
 * priority_queue <int,vector<int>,less<int> >q;
 */

// @lc code=start
#include <vector>
#include <queue>

class Solution
{
public:
    std::priority_queue<int,std::vector<int>, std::greater<int>> queue; // 大顶堆 降序
    int findKthLargest(std::vector<int> &nums, int k)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (queue.size() < k)
            {
                queue.push(nums[i]);
            }
            else
            {
                if (nums[i] > queue.top())
                {
                    queue.pop();
                    queue.push(nums[i]);
                }
            }
        }
        return queue.top();
    }
};
// @lc code=end
