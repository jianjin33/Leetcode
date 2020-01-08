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
            while (j > 0 && temp < nums[j - 1])
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
    vector<int> bucketSort(vector<int> &nums)
    {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int n = high - low + 1;
        vector<int> buckets(n);
        for (auto x : nums)
            ++buckets[x - low];
        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < buckets[i]; ++j)
            {
                res.push_back(i + low);
            }
        }
        return res;
    }

    /** 
     * 堆排序 大小顶堆 72 ms
     */
    void heapify(vector<int> &nums, int i, int len)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i; // 假设i大

        // i分别与它的左右子节点比大小
        if (left < len && nums[left] > nums[largest])
            largest = left;

        if (right < len && nums[right] > nums[largest])
            largest = right;

        if (largest != i)
        {
            swap(nums[largest], nums[i]);
            heapify(nums, largest, len);
        }
    }

    vector<int> heapSort(vector<int> &nums)
    {
        // 构建大顶堆
        int len = nums.size();
        for (int i = nums.size() / 2; i >= 0; i--)
            heapify(nums, i, len);

        for (int i = len - 1; i > 0; i--)
        {
            // 顶部和最后一个最大值交换，在做下沉操作
            swap(nums[0], nums[i]);
            heapify(nums, 0, i);
        }
        return nums;
    }

    vector<int> quickSort(vector<int> &nums, int L, int R)
    {
        int i = L;
        int j = R;
        int pivot = nums[(L + R) / 2];

        while (i <= j)
        {
            while (pivot > nums[i])
            {
                i++;
            }
            while (pivot < nums[j])
            {
                j--;
            }

            if (i <= j)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        if (L < j)
        {
            quickSort(nums, L, j);
        }

        if (R > i)
        {
            quickSort(nums, i, R);
        }

        return nums;
    }

    vector<int> quickSortV2(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return nums;

        int t = nums[l + (r - l) / 2];
        int tl = l;
        int tr = r;
        for (int i = tl; i <= tr;)
        {
            if (nums[i] == t)
            {
                ++i;
            }
            else if (nums[i] < t)
            {
                swap(nums[i++], nums[tl++]);
            }
            else
            {
                swap(nums[i], nums[tr--]);
            }
        }
        quickSortV2(nums, l, tl - 1);
        quickSortV2(nums, tr + 1, r);
        return nums;
    }

    vector<int> shellSort(vector<int> &nums)
    {
        int length = nums.size();
        for (int step = length / 2; step > 0; step = step /= 2)
        {
            for (int j = step; j < length; j++)
            {
                int temp = nums[j], pre = j;
                while (pre - step >= 0 && temp < nums[pre - step])
                {
                    nums[pre] = nums[pre - step];
                    pre -= step;
                }
                nums[pre] = temp;
            }
        }
        return nums;
    }

    void merge(vector<int> &nums, int left, int mid, int right)
    {
        vector<int> temp;
        int i = 0;
        int p1 = left;
        int p2 = mid + 1;
        while (p1 <= mid && p2 <= right)
        {
            temp[i++] = nums[p1] > nums[p2] ? nums[p2++] : nums[p1++];
        }

        while (p1 <= mid)
            temp[i++] = nums[p1++];

        while (p2 <= right)
            temp[i++] = nums[p2++];

        for (int i = 0; i < temp.size(); i++)
        {
            nums[left + i] = temp[i];
        }
    }

    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return;
        }
        int mid = left + ((right - left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
        return;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.empty())
        {
            return {};
        }

        // return bubbleSort(nums);
        // return insertSort(nums);
        // return bucketSort(nums);
        // return heapSort(nums);
        // return quickSort(nums, 0, nums.size()-1);
        // return quickSortV2(nums, 0, nums.size()-1);
        // return shellSort(nums);
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
