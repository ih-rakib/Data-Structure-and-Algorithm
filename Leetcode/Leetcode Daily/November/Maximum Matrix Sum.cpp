// https://leetcode.com/problems/maximum-matrix-sum/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long sum = 0;
        int mn = INT_MAX, negative = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0) {
                    negative++;
                }
                mn = min(mn, abs(matrix[i][j]));
            }
        }

        // cout << mn << '\n';

        return (negative & 1 ? sum - 2*mn : sum);
    }
};

// Author: Ikramul Hasan Rakib