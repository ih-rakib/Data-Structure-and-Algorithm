// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-bonus-problem/problem/create-a-spiral-matrix-of-nm-size-from-given-array

class Solution {
  public:
    vector<vector<int>> spiralFill(int n, int m, vector<int> &arr) {
        vector<vector<int>> mat(n, vector<int> (m, 0));
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        int id = 0;

        while(top <= bottom and left <= right) {
            for(int i = left; i <= right; ++i) {
                mat[top][i] = arr[id]; id++;
            }
            top++;

            for(int i = top; i <= bottom; ++i) {
                mat[i][right] = arr[id]; id++;
            }
            right--;

            if(top <= bottom) {
                for(int i = right; i >= left; --i) {
                    mat[bottom][i] = arr[id]; id++;
                }
                bottom--;
            }

            if(left <= right) {
                for(int i = bottom; i >= top; --i) {
                    mat[i][left] = arr[id]; id++;
                }
                left++;
            }
        }
        return mat;
    }
};

// Author: Ikramul Hasan Rakib