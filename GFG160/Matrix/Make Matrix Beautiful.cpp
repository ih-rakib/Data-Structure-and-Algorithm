// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-bonus-problem/problem/make-matrix-beautiful-1587115620

class Solution {
  public:
    int findMinOperation(vector<vector<int> >& mat) {
        int n = mat.size();
        vector<int> rowSum(n, 0), colSum(n, 0);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }

        int maxSum = 0;
        for(int i = 0; i < n; ++i) {
            maxSum = max(maxSum, max(rowSum[i], colSum[i]));
        }

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += (maxSum - rowSum[i]);
        }
        return ans; 
    }
};

// Author: Ikramul Hasan Rakib