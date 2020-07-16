/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        int min_length = numeric_limits<int>::max();
        for (const string &s : strs)
        {
            if (s.size() < min_length)
            {
                min_length = s.size();
            }
        }
        for (int i = 0; i < min_length; ++i)
        {
            char comp = strs[0][i];

            for (const string &s : strs)
            {
                if (s[i] != comp)
                {
                    if (i == 0)
                    {
                        return "";
                    }
                    else
                    {
                        return strs[0].substr(0, i);
                    }
                }
            }
        }
        return strs[0].substr(0, min_length);
    }
};
// @lc code=end
