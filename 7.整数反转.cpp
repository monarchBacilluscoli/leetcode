/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        long current = 0;
        while (x != 0)
        {
            //! 每次都要check，因为指不定啥时候就超了
            if (current * 10 + x % 10 > ((long)2 << 31) - 1 || current * 10 + x % 10 < -((long)2 << 31))
            {
                return 0;
            }
            current = current * 10 + x % 10;
            x /= 10;
        }

        return current;
    }
};
// @lc code=end
