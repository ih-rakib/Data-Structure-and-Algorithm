// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

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
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        reverseLevels(root->left, root->right, 1);
        return root;
    }

private: 
    void reverseLevels(TreeNode* left, TreeNode* right, int level) {
        if(!left or !right) return;

        if(level & 1) {
            swap(left->val, right->val);
        }

        reverseLevels(left->left, right->right, level + 1);
        reverseLevels(left->right, right->left, level + 1);
    }
};

// Author: Ikramul Hasan Rakib