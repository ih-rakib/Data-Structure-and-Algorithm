// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/

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
    // Array to store the maximum height of the tree after removing each node
    int maxHeightAfterRemoval[100001];
    int currentMaxHeight = 0;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // First traversal: Left to Right
        traverseLeftToRight(root, 0);
        currentMaxHeight = 0;  // Reset for the second traversal
        // Second traversal: Right to Left
        traverseRightToLeft(root, 0);

        // Prepare results for the queries
        vector<int> queryResults(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            queryResults[i] = maxHeightAfterRemoval[queries[i]];
        }

        return queryResults;
    }

private:
    // First traversal to calculate heights
    void traverseLeftToRight(TreeNode* node, int currentHeight) {
        if (!node) return;  // Base case for recursion

        // Store the height before reaching this node/after removing this node
        maxHeightAfterRemoval[node->val] = currentMaxHeight;

        // Update current maximum height based on the height at this node
        currentMaxHeight = max(currentMaxHeight, currentHeight);

        // Traverse left and right children
        traverseLeftToRight(node->left, currentHeight + 1);
        traverseLeftToRight(node->right, currentHeight + 1);
    }

    // Second traversal to ensure all maximum heights are captured
    void traverseRightToLeft(TreeNode* node, int currentHeight) {
        if (!node) return;  // Base case for recursion

        // Update maxHeightAfterRemoval for the current node
        maxHeightAfterRemoval[node->val] = max(maxHeightAfterRemoval[node->val], currentMaxHeight);

        // Update the current maximum height based on the height at this node
        currentMaxHeight = max(currentHeight, currentMaxHeight);

        // Traverse right and left children
        traverseRightToLeft(node->right, currentHeight + 1);
        traverseRightToLeft(node->left, currentHeight + 1);
    }
};
