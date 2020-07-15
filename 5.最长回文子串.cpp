/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// #include <string>
// using namespace std;

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
        for (int i = 0; i < s.size(); ++i)
        {
            // from a char
            int current_length = 1;
            for (int j = 1;; ++j)
            {
                if (i + j < s.size() && i - j >= 0 && s[i + j] == s[i - j])
                {
                    current_length += 2;
                }
                else
                {
                    if (current_length > max_string.size())
                    {
                        max_string = s.substr(i - j + 1, 2 * (j - 1) + 1);
                    }
                    break;
                }
            }
            // between two chars
            current_length = 0;
            for (int j = 0;; ++j)
            {
                if (i + 1 + j < s.size() && i - j >= 0 && s[i + 1 + j] == s[i - j])
                {
                    current_length += 2;
                }
                else
                {
                    if (current_length > max_string.size())
                    {
                        max_string = s.substr(i - j + 1, 2 * (j - 1) + 2);
                    }
                    break;
                }
            }
        }
        return max_string;
    }
};
// @lc code=end
