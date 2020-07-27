/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isValidBST_(TreeNode *root, long upper, long lower)
    {
        if (!root)
        {
            return true;
        }
        if (root->val <= lower)
        {
            return false;
        }
        if (root->val >= upper)
        {
            return false;
        }
        return isValidBST_(root->left, root->val, lower) && isValidBST_(root->right, upper, root->val);
    }

    bool isValidBST(TreeNode *root)
    {
        return isValidBST_(root, numeric_limits<long>::max(), numeric_limits<long>::lowest());
    }
};
// @lc code=end
