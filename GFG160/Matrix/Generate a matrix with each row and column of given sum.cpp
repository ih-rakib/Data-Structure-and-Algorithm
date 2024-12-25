// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-bonus-problem/problem/generate-a-matrix-with-each-row-and-column-of-given-sum

class Solution {
  public:
    vector<vector<int>> generateMatrix(vector<int> rowSum, vector<int> colSum) {
        int n = rowSum.size(), m = colSum.size();

        vector<vector<int>> mat(n, vector<int> (m, 0));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int val = min(rowSum[i], colSum[j]);
                mat[i][j] = val;

                rowSum[i] -= val;
                colSum[j] -= val;
            }
        }
        return mat;
    }
};

// Author: Ikramul Hasan Rakib