/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        std::vector<std::vector<int>> result(0, std::vector<int>());
        std::unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); ++i)
        {
            ++nums_map[nums[i]];
        }
        for (auto &&n : nums_map)
        {
            int two_sum = 0 - n.first;
            --n.second;
            unordered_map<int, int> t = nums_map;
            for (auto &&m : t)
            {
                if (m.second > 0)
                {
                    --m.second;
                    if (m.second >= 0 && t.find(two_sum - m.first) != t.end() && t[two_sum - m.first] != 0)
                    {
                        result.emplace_back(std::vector<int>{n.first, m.first, two_sum - m.first});
                        t[two_sum - m.first] = 0;
                        m.second = 0;
                    }
                }
            }
            n.second = 0;
        }
        for (std::vector<int> &r : result)
        {
            std::sort(r.begin(), r.end());
        }
        return result;
    }
};
// @lc code=end
