// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-matrix17201720

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size();

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] == x) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Author: Ikramul Hasan Rakib