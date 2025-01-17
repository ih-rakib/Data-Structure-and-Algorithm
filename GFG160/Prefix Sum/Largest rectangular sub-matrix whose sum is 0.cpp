// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-bonus-problem/problem/largest-rectangular-sub-matrix-whose-sum-is-0

class Solution {
  public:
    int zeroSumSubmat(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int ans = 0;
        
        for(int top = 0; top < rows; ++top) {
            vector<int> colSum(cols, 0);
            
            for(int bottom = top; bottom < rows; ++bottom) {
                for(int col = 0; col < cols; ++col) {
                    colSum[col] += mat[bottom][col];
                }
                
                unordered_map<int, int> pSumMap;
                pSumMap[0] = -1;
                int psum = 0;
                
                for(int col = 0; col < cols; ++col) {
                    psum += colSum[col];
                    
                    if(pSumMap.find(psum) != pSumMap.end()) {
                        int startCol = pSumMap[psum] + 1;
                        int subArea = (bottom - top + 1) * (col - startCol + 1);
                        
                        ans = max(ans, subArea);
                    }
                    
                    if(pSumMap.find(psum) == pSumMap.end()) {
                        pSumMap[psum] = col;
                    }
                }
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib