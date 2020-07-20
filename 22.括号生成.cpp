/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
    std::vector<string> results;

    void generateParenthesis_(std::string current, int left, int right) // 当前string， 剩余左括号，剩余右括号
    {
        if (left > right) //有右括号待填充
        {
            return;
        }
        if (left > 0) // 可以放left
        {
            generateParenthesis_(current + '(', left - 1, right);
        }
        if (right > 0 && right > left) // 可以放right
        {
            generateParenthesis_(current + ')', left, right - 1);
        }
        if (left == 0 && right == 0)
        {
            results.push_back(current);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        generateParenthesis_("", n, n);
        return results;
    }
};
// @lc code=end
