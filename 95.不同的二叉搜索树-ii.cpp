/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> generateTrees_(const std::vector<int> &nums, int start, int size) //左闭又开区间
    {
        vector<TreeNode *> results(0);
        if (size <= 0)
        {
            return results;
        }
        else if (size == 1)
        {
            results.push_back(new TreeNode(nums[start]));
            return results;
        }
        else
        {
            for (int i = start; i < start + size; ++i)
            {
                vector<TreeNode *> lefts = generateTrees_(nums, start, i - start);
                vector<TreeNode *> rights = generateTrees_(nums, i + 1, size - (i - start) - 1);
                if (!lefts.empty() && !rights.empty())
                {
                    for (int j = 0; j < lefts.size(); ++j) //todo 排列组合，哪怕是0也有null
                    {
                        for (int k = 0; k < rights.size(); ++k)
                        {
                            TreeNode *root = new TreeNode(nums[i]);
                            root->left = lefts[j];
                            root->right = rights[k];
                            results.push_back(root);
                        }
                    }
                }
                else if (lefts.empty())
                {
                    for (int k = 0; k < rights.size(); ++k)
                    {
                        TreeNode *root = new TreeNode(nums[i]);
                        root->right = rights[k];
                        results.push_back(root);
                    }
                }
                else if (rights.empty())
                {
                    for (int j = 0; j < lefts.size(); ++j)
                    {
                        TreeNode *root = new TreeNode(nums[i]);
                        root->left = lefts[j];
                        results.push_back(root);
                    }
                }
            }
            return results;
        }
    }

    vector<TreeNode *> generateTrees(int n)
    {
        std::vector<int> nums(n);
        std::iota(nums.begin(), nums.end(), 1);
        return generateTrees_(nums, 0, n);
    }
};
// @lc code=end
