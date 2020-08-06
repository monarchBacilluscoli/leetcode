/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int result = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            result ^= nums[i];
        }
        return result;
    }
};
// @lc code=end
