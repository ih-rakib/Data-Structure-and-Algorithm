// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-bonus-problem/problem/c-matrix-rotation-by-180-degree0745

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int ni = n - i - 1;
                int nj = n - j - 1;

                if(i < ni or (i == ni and j < nj)) {
                    swap(mat[i][j], mat[ni][nj]);
                }
            }
        }
    }
};

// Author: Ikramul Hasan Rakib