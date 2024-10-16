// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int> > dp(n, vector<int> (m, 0));

        dp[0][0] = grid[0][0];

        // fill first row (can only come from left)
        for(int j = 1; j < m; ++j) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        // fill first column (can only come from above)
        for(int i = 1; i < n; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        // fill rest of the dp table
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};