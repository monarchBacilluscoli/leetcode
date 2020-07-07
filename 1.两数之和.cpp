/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (48.91%)
 * Likes:    8579
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.4M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */

#include <vector>
#include <stdexcept>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++)
        {
            auto t = indices.find(target - nums[i]);
            // 因为恰好有两个数可以构成，check第一个数不成，check第二个数的时候一定成
            if (t != indices.end())
            {
                return {t->second, i};
            }
            indices[nums[i]] = i;
        }
        throw runtime_error("no such pair");
    }
};
// @lc code=end
