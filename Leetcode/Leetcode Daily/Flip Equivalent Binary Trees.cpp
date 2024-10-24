// https://leetcode.com/problems/flip-equivalent-binary-trees/

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // if both are null
        if(!root1 and !root2) return true;

        // if one is null and another is not
        if(!root1 or !root2) return false;

        // val of root1 != val of root2
        if(root1->val != root2->val) return false;

        // case 1: left subtree of root1 matches the left subtree of root2 and vice versa
        // case 2: left subtree of root1 matches the right subtree of root2 and vice versa
        return flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right) or
               flipEquiv(root1->left, root2->right) and flipEquiv(root1->right, root2->left);
    }
};