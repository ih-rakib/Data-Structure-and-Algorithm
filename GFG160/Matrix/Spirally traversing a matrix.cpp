// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/spirally-traversing-a-matrix-1587115621

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int> ans;

        if(mat.empty()) return 0;

        int top = 0, bottom = matrix.size();
        int left = 0, right = matrix[0].size();

        while(top <= bottom and left <= right) {
            for(int i = left; i <= right; ++i) {
                ans.push_back(mat[top][i]);
            }
            top++;

            for(int i = top; i <= bottom; ++i) {
                ans.push_back(mat[i][right]);
            }   
            right--;

            if(top <= bottom) {
                for(int i = right; i >= left; --i) {
                    ans.push_back(mat[bottom][i]);
                }
            }
            bottom--;

            if(left <= right) {
                for(int i = bottom; i >= top; --i) {
                    ans.push_back(mat[i][left]);
                }
            }
            left++;
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib