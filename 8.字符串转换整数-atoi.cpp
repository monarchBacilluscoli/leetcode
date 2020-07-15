/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution
{
public:
    int myAtoi(string str)
    {
        long long result = 0;
        unordered_set<char> nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
        if (str.size() == 0)
        {
            return 0;
        }
        int op = 1;
        int start = 0;
        for (start = 0; start < str.size(); ++start)
        {
            if (nums.find(str[start]) != nums.end() && str[start] != 0) //首数字找到
            {
                break;
            }
            else if (str[start] == '-') // 首负号找到
            {
                if (start + 1 < str.size() && nums.find(str[start + 1]) != nums.end()) // 负号并且后有数
                {
                    op = -1;
                    ++start;
                    break;
                }
                else // 负号并且后无数
                {
                    return 0;
                }
            }
            else if (str[start] == '+') // 首正号找到
            {
                if (start + 1 < str.size() && nums.find(str[start + 1]) != nums.end()) // 正号并且后有数
                {
                    ++start;
                    break;
                }
                else // 正号并且后无数
                {
                    return 0;
                }
            }
            else if (str[start] == ' ')
            {
            }
            else
            {
                return 0;
            }
        }
        for (int i = start; i < str.size() && nums.find(str[i]) != nums.end(); ++i)
        {
            int current = str[i] - 48;
            if (op > 0 && result > ((long long)INT32_MAX - current) / 10)
            {
                return INT32_MAX;
            }
            else if (op < 0 && result * (-1) < ((long long)INT32_MIN + current) / 10)
            {
                return INT32_MIN;
            }
            else
            {
                result = result * 10 + current;
            }
        }

        return result * op;
    }
};
// @lc code=end
