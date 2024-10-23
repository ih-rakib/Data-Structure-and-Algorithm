// https://leetcode.com/problems/cousins-in-binary-tree-ii/

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;

        // BFS queue
        queue<TreeNode*> q;
        q.push(root);

        // Set root's value to 0 (root has no cousins)
        root->val = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            long long curLevelSum = 0;

            // First pass: calculate the total sum of current level
            vector<TreeNode*> levelNodes;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelNodes.push_back(node);

                // Enqueue the children and calculate total sum
                if (node->left) {
                    curLevelSum += node->left->val;
                    q.push(node->left);
                }
                if (node->right) {
                    curLevelSum += node->right->val;
                    q.push(node->right);
                }
            }

            // Second pass: update values with cousin sums
            for (TreeNode* node : levelNodes) {
                long long siblingSum = 0;

                // Calculate the sum of siblings
                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;

                // Cousin sum = total level sum - sibling sum
                if (node->left) node->left->val = curLevelSum - siblingSum;
                if (node->right) node->right->val = curLevelSum - siblingSum;
            }
        }
        return root;
    }
};

// Cousins are nodes that are at the same depth in the tree but have different parents