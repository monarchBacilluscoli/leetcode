/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        int num_columns;
        num_columns = ceil(s.size() / (double)(2 * numRows - 2)) * (numRows - 1);
        std::vector<std::vector<char>> matrix(numRows, std::vector<char>(num_columns, '\0'));
        int x = 0, y = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            matrix[y][x] = s[i];
            if (x % (numRows - 1) == 0 && y != numRows - 1)
            {
                // direct: down
                ++y;
            }
            else
            {
                // direct: upper right
                ++x;
                --y;
            }
        }
        string output = "";
        for (size_t i = 0; i < numRows; ++i)
        {
            for (size_t j = 0; j < num_columns; ++j)
            {
                if (matrix[i][j] != '\0')
                {
                    output.push_back(matrix[i][j]);
                }
            }
        }
        return output;
    }
};
// @lc code=end
