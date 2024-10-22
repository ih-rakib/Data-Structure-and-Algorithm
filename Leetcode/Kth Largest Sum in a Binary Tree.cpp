// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/ 

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return -1; // if tree is empty

        queue<TreeNode*> q;
        q.push(root);

        vector<long long> levelSums;

        while(!q.empty()){
            int levelSize = q.size();
            long long curLevelSum = 0;

            for(int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Add current node's value to the level sum
                curLevelSum += node -> val;

                // Add children to the queue for the next level
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }

            levelSums.push_back(curLevelSum);
        }

        if(levelSums.size() < k) return -1;
        
        sort(levelSums.begin(), levelSums.end(), greater<long long> ());

        return levelSums[k-1];
    }
};