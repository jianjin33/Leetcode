/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void swap(int &a, int &b)
    {
        int temp = a ^ b;
        a = a ^ temp;
        b = b ^ temp;
    }

    /**
    * 冒泡
    * 最好：O(n)，只冒泡一次数组就有序的情况。
    * 最坏：O(n2)
    * 平均：O(n2)
    */
    vector<int> bubbleSort(vector<int> &nums)
    {
        int length = nums.size();
        for (size_t i = 0; i < length; i++)
        {
            // 如果一轮比较中没有需要交换的数据，则说明数组已经有序。主要是对[5,1,2,3,4]之类的数组进行优化
            bool mark = true;
            for (size_t j = 0; j < length - i - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                    mark = false;
                }
            }
            if (mark)
                return nums;
        }
        return nums;
    }

    /**
     * 插入 
     * 以第一个元素作为有序数组，其后的元素通过在这个已有序的数组中找到合适的位置并插入
     * 最好：O(n)，原数组已经是升序的  
     * 最坏：O(n2)， 原数组已经是降序的
     * 平均：O(n2)
     */
    vector<int> insertSort(vector<int> &nums)
    {
        int length = nums.size();
        for (int i = 1; i < length; i++)
        {
            int temp = nums[i];
            int j = i;
            while (j > 0  && temp < nums[j - 1])
            {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = temp;
        }

        return nums;
    }

    /**
     * 桶排序 68 ms
     */
    vector<int> bucketSort(vector<int>& nums) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int n = high - low + 1;
        vector<int> buckets(n);
        for (auto x : nums) ++buckets[x - low];
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < buckets[i]; ++j) {
                res.push_back(i + low);
            }
        }
        return res;
    }


    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.empty())
        {
            return {};
        }
        
        // return bubbleSort(nums);
        // return insertSort(nums);
        return bucketSort(nums);
    }
};
