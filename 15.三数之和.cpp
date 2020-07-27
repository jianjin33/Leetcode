/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 * 第一步：为避免重复，所以先进行一次排序，再遍历
 * 第二步：依次以 -nums[i]作为结果，分别从i+1向后开始
 *  和 nums.size()-1向前开始，查询两数之和为 -nums[i]；
 * 
 */
#include <vector>
#include <list>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &num)
    {
        vector<vector<int>> res;

        sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++)
        {
            int target = -num[i];
            int front = i + 1, back = num.size() - 1;

            while (front < back)
            {

                int sum = num[front] + num[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else
                {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);

                    // 继续下一个
                    while (front < back && num[front] == triplet[1])
                        front++;

                    // 继续下一个
                    while (front < back && num[back] == triplet[2])
                        back--;
                }
            }

            // 略过重复元素
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;
        }

        return res;
    }
};
