import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=3 lang=java
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxLength = 0, startIndex = -1;
        HashMap<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                startIndex = Math.max(map.get(c), startIndex);
            }
            maxLength = Math.max(maxLength, i - startIndex);
            map.put(c, i);
        }
        return maxLength;
    }
}
// @lc code=end
