/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start

//Definition for a binary tree node.

// #include <vector>

// using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
        {
            return vector<int>();
        }
        vector<int> result;
        vector<int> temp;
        if (root->left)
        {
            temp = inorderTraversal(root->left);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        result.push_back(root->val);
        if (root->right)
        {
            temp = inorderTraversal(root->right);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        return result;
    }
};
// @lc code=end
