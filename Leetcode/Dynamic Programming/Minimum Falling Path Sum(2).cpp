// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int row = 1; row < n; ++row) {
            for(int col = 0; col < n; ++col) {
                int best = matrix[row-1][col];
                if(col > 0) best = min(best, matrix[row-1][col-1]);
                if(col < n-1) best = min(best, matrix[row-1][col+1]);
                matrix[row][col] += best;
            }
        }
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};