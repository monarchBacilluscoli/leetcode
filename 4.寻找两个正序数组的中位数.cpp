/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start

#include <vector>
#include <limits>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int sum = nums1.size() + nums2.size();
        int n = sum / 2;

        // 合并
        std::vector<int> final(n + 1);
        int a = 0;
        int b = 0;
        for (size_t i = 0; i <= n; i++)
        {
            int t1, t2;
            if (a >= nums1.size())
            {
                t1 = numeric_limits<int>::max();
            }
            else
            {
                t1 = nums1[a];
            }

            if (b >= nums2.size())
            {
                t2 = numeric_limits<int>::max();
            }
            else
            {
                t2 = nums2[b];
            }

            if (t1 > t2)
            {
                final[i] = t2;
                ++b;
            }
            else
            {
                final[i] = t1;
                ++a;
            }
        }

        if (sum % 2)
        {
            return final[n];
        }
        else
        {
            return (final[n] + final[n - 1]) / 2.0;
        }
    }
};
// @lc code=end
