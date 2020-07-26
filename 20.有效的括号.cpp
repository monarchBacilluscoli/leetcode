/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    const std::unordered_map<char, char> braket_map{{')', '('}, {']', '['}, {'}', '{'}};
    
    bool isValid(std::string s)
    {
        std::stack<char> brakets;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (!brakets.empty() && braket_map.find(brakets.top()) != braket_map.end() && s[i] == braket_map.at(brakets.top()))
            {
                brakets.pop();
                s.pop_back();
            }
            else
            {
                brakets.push(s.back());
                s.pop_back();
            }
        }
        if (brakets.empty() && s.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
