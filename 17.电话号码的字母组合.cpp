/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    std::unordered_map<char, vector<string>> nums_to_letters{
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}},
    };

    vector<string>
    letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return vector<string>();
        }
        if (digits.size() == 1)
        {
            return nums_to_letters[digits.front()];
        }
        else
        {
            std::vector<string> result{};
            char t = digits.back();
            digits.pop_back();
            std::vector<string> result2 = letterCombinations(digits);
            for (const string &c : nums_to_letters[t])
            {
                for (const string &s : result2)
                {
                    result.emplace_back(s + c);
                }
            }
            return result;
        }
    }
};
// @lc code=end
