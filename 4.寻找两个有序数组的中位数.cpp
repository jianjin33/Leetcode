/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 * 解题思路: 排序数字的第k位大／小的数
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution
{
private:
    void pushQueue(vector<int> &nums, priority_queue<int, vector<int>, greater<int>> &smallQueue,
                   priority_queue<int, vector<int>, less<int>> &bigQueue)
    {
        int n = nums.size();
        while (n)
        {
            int num = nums[n - 1];
            n--;
            if (smallQueue.empty())
            {
                smallQueue.push(num);
                return;
            }

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
                    bigQueue.push(num);
                else
                    smallQueue.push(num);
            }
        }
    }

    int kth(vector<int> &nums1, int start1, int end1, vector<int> &nums2, int start2, int end2, int k)
    {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        // 调换数组位置，避免多次判断 麻烦, 有空数组 就一定是num1
        if (len1 > len2)
            return kth(nums2, start2, end2, nums1, start1, end1, k);
        if (len1 == 0)
            return nums2[start2 + k - 1]; // 找到

        if (k == 1)
            return min(nums1[start1], nums2[start2]); // 找到

        int i = start1 + min(len1, k / 2) - 1;
        int j = start2 + min(len2, k / 2) - 1;
        if (nums1[i] > nums2[j])
            return kth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1)); // 去掉肯定不会在的范围 继续递归查找第 k － 排除大小 个大／小的数字
        else
            return kth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        /*        priority_queue<int, vector<int>, greater<int>> smallQueue; // 大顶堆 降序
        priority_queue<int, vector<int>, less<int>> bigQueue;

        pushQueue(nums1, smallQueue, bigQueue);
        pushQueue(nums2, smallQueue, bigQueue);

        if (smallQueue.size() == bigQueue.size())
            return static_cast<double>(smallQueue.top() + bigQueue.top()) / 2;
        else
            return smallQueue.size() > bigQueue.size() ? smallQueue.top() : bigQueue.top();
 */
        int n = nums1.size();
        int m = nums2.size();

        int k = (n + m + 1) / 2;
        int m1 = kth(nums1, 0, n - 1, nums2, 0, m - 1, k);
        if ((n + m) % 2 == 0)
        {
            // 偶数情况，取第k＋1位
            int m2 = kth(nums1, 0, n - 1, nums2, 0, m - 1, k + 1);
            return static_cast<double>(m1 + m2) / 2.0;
        }
        return m1;
    }
};
// @lc code=end
