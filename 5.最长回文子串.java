/*
 * @lc app=leetcode.cn id=5 lang=java
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
    public String longestPalindrome(String s) {
        int maxStart = 0, maxLength = 0, length = s.length();

        for (int i = 0; i < length;) {
            int start = i, end = i;
            while (end + 1 < length && s.charAt(end) == s.charAt(end + 1)) {
                end++;
            }
            i = end + 1;
            while (start - 1 >= 0 && end + 1 < length && s.charAt(start - 1) == s.charAt(end + 1)) {
                --start;
                ++end;
            }

            if ((end - start + 1) > maxLength) {
                maxLength = end - start + 1;
                maxStart = start;
            }
        }

        return s.substring(maxStart, maxStart + maxLength);
    }
}
// @lc code=end
