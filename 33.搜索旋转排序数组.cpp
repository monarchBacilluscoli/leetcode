/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return -1;
        }

        int left = 0, right = nums.size();
        bool is_left_part = target > nums[0] ? true : false;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if ((is_left_part && nums[mid] > nums[0] && target > nums[mid]) || (!is_left_part && (nums[mid] < nums[0] && target > nums[mid]) || nums[mid] > nums[0])) // 向右折半
            {
                left = mid + 1; // 注意+1和-1
            }
            else // 向左折半
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
