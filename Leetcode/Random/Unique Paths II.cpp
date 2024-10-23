// https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int> > dp(n, vector<int> (m, 0));

        if(obstacleGrid[0][0] == 1 or obstacleGrid[n-1][m-1] == 1) {
            return 0;
        }

        dp[0][0] = 1;

        // fill first row
        for(int i = 1; i < m; ++i) {
            dp[0][i] = (obstacleGrid[0][i] == 0) ? dp[0][i-1] : 0;
        }

        // fill first column
        for(int j = 1; j < n; ++j){
            dp[j][0] = (obstacleGrid[j][0]) == 0 ? dp[j-1][0] : 0;
        }

        // fill rest of dp table
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                if(obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n-1][m-1];
    }
};