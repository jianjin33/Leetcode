/*
 * @lc app=leetcode.cn id=2042 lang=java
 *
 * [2042] 检查句子中的数字是否递增
 */

// @lc code=start
class Solution {
    public boolean areNumbersAscending(String s) {
        String[] items = s.split(" ");
        int length = items.length;
        int cur = -1;
        for(int i = 0; i < length; ++i) {
            String item = items[i];
            if(!Character.isDigit(item.charAt(0))) {
                continue;
            }
            int value = Integer.valueOf(item);
            if (value <= cur) {
                return false;
            }
            cur = value;
        }
        return true;
    }
}
// @lc code=end

