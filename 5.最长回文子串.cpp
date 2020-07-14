/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0)
        {
            return "";
        }
        string max_string = "";
        for (size_t i = 0; i < s.size(); i++)
        {
            int current_length = 1;
            for (size_t j = 0;; j++)
            {
                if (i + j < s.size() && i - j >= 0 && s[i + j] == s[i - j])
                {
                    ++current_length;
                }
                else
                {
                    if (current_length > max_string.size())
                    {
                        max_string = string::
                    }
                }
            }
        }
        return max_length;
    }
};
// @lc code=end
