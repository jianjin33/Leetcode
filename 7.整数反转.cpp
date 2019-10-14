/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <limits>

class Solution
{
public:
    int reverse(int x)
    {
        // 注意：result不赋初值的话会给出-8589934..因为函数体内部是不能默认初始化的
        // 可以写在方法外，默认初始化的值就正常了。
        long result = 0;    
        while (x != 0)
        {
            /**
             * 123 第一次循环取得3 即可 然后通过/10的方式去掉3，变成了一个两位数
             * 
             * 12 第二次循环，之前result = 3 需要在后面拼接一个2，即32，
             * 可通过3 * 10 = 30，然后通过%的方式获取2，与30相加，即32。
             * 同样通过/10的方式去掉2
             **/
            result = result * 10 + x % 10;
            x /= 10;
        }

        return (result < INT_MIN || result > INT_MAX) ? 0 : result;
    }
};
