/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
        {
            return 0;
        }
        string::iterator a = s.begin();
        string::iterator b = s.begin() + 1;
        int max_length = 1;
        int current_length = 1;
        unordered_map<char, int> letter_indices;
        letter_indices[*a] = 0;
        while (b != s.end())
        {
            //todo 如果出现重复,move a跳过重复头,
            //todo 如果不重复,++b
            auto found = letter_indices.find(*b);
            if (found != letter_indices.end() && found->second - (a - s.begin()) >= 0)
            {
                a = s.begin() + found->second + 1;
                letter_indices[*b] = b - s.begin();
                ++b;
            }
            else
            {
                // 为了使程序在尾部边界也可以运行，我们应该在“b所指的当下”进行计算length而不是等b已经check到相似或end了才处理。
                int length = b - a + 1;
                if (length > max_length)
                {
                    max_length = length;
                }
                letter_indices[*b] = b - s.begin();
                ++b;
            }
        }
        return max_length;
    }
};
// @lc code=end
