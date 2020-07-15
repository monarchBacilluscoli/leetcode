/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

#include <cmath>

class Solution
{
public:
    int calculateVolume(int i, int j, int h_i, int h_j)
    {
        return std::abs(i - j) * (h_i > h_j ? h_j : h_i);
    }

    int maxArea(vector<int> &height)
    {
        int max_volume = 0;
        int current_v = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            current_v = calculateVolume(left, right, height[left], height[right]);
            if (current_v > max_volume)
            {
                max_volume = current_v;
            }
            if (height[left] < height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return max_volume;
    }
};
// @lc code=end
