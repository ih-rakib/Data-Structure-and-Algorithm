// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int> > dp(n, vector<int> (n, 0));

        // first row will be as it is
        for(int col = 0; col < n; ++col) dp[0][col] = matrix[0][col];

        for(int row = 1; row < n; ++row) {
            for(int col = 0; col < n; ++col) {
                // directly above
                dp[row][col] = dp[row-1][col];

                // left
                if(col > 0) dp[row][col] = min(dp[row][col], dp[row-1][col-1]);
                
                // right
                if(col < n-1) dp[row][col] = min(dp[row][col], dp[row-1][col+1]);


                dp[row][col] += matrix[row][col];
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};