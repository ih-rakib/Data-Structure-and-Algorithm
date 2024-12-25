// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/set-matrix-zeroes

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();

        bool firstRow = false, firstCol = false;

        for(int j = 0; j < m; ++j) {
            if(mat[0][j] == 0) {
                firstRow = true; break;
            }
        }

        for(int i = 0; i < n; ++i) {
            if(mat[i][0] == 0) {
                firstCol = true; break;
            }
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                if(mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                if(mat[i][0] == 0 or mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        if(firstRow) {
            for(int j = 0; j < m; ++j) {
                mat[0][j] = 0;
            }
        }

        if(firstCol) {
            for(int i = 0; i < n; ++i) {
                mat[i][0] = 0;
            }
        }
        
    }
};

// Author: Ikramul Hasan Rakib