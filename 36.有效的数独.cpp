/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution
{
private:
    std::vector<std::unordered_set<char>> rows{9};
    std::vector<std::unordered_set<char>> columns{9};
    std::vector<std::unordered_set<char>> blocks{9};

public:
    //todo 空是’.‘
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    char current = board[i][j];
                    if (rows[i].find(current) == rows[i].end())
                    {
                        rows[i].insert(current);
                    }
                    else
                    {
                        return false;
                    }

                    if (columns[j].find(current) == columns[j].end())
                    {
                        columns[j].insert(current);
                    }
                    else
                    {
                        return false;
                    }
                    int block_index = (i / 3) * 3 + j / 3;
                    if (blocks[block_index].find(current) == blocks[block_index].end())
                    {
                        blocks[block_index].insert(current);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
