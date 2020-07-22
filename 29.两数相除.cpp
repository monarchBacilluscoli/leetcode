/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
        {
            return 0;
        }
        int op = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) ? -1 : 1;
        int sum = 0;
        int times = 0;
        dividend = dividend < 0 ? dividend : -dividend;
        divisor = divisor < 0 ? divisor : -divisor;
        while (sum >= dividend)
        {
            if (sum < std::numeric_limits<int>::min() - divisor)
            {
                return numeric_limits<int>::max();
            }
            sum += divisor;
            ++times;
        }
        return (times - 1) * op;
    }
};
// @lc code=end
