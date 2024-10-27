// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        vector<vector<int> > dp(n, vector<int> (m, 0));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] == 1) {
                    if(i == 0 or j == 0) {
                     // If it's the first row or first column, the largest square ending here is itself
                        dp[i][j] = 1; 
                    }else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};

// dp[i][j] = largest square that can be formed at cell (i,j) with all ones