/*
 * @lc app=leetcode.cn id=2044 lang=java
 *
 * [2044] 统计按位或能得到最大值的子集数目
 */

// @lc code=start
class Solution {
    int count, maxOr = 0;
    int[] nums;

    public int countMaxOrSubsets(int[] nums) {
        this.nums = nums;
        maxOr = 0;
        count = 0;
        dfs(0, maxOr);
        return count;
    }

    private void dfs(int pos, int orVal) {
        if (pos == nums.length) {
            if (orVal > maxOr) {
                count = 1;
                maxOr = orVal;
            } else if (orVal == maxOr) {
                ++count;
            }
            return;
        }
        dfs(pos + 1, nums[pos] | orVal);
        dfs(pos + 1, orVal);
    }
}
// @lc code=end
