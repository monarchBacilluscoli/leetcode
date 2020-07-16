/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        for (size_t i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != *(s.end() - i - 1))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
