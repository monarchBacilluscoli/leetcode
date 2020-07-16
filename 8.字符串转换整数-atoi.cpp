/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <string>

// @lc code=start
class Solution
{
public:
    int myAtoi(string str)
    {
        try
        {
            return std::stoi(str);
        }
        catch (const std::exception &e)
        {
            return 0;
        }
    }
};
// @lc code=end
