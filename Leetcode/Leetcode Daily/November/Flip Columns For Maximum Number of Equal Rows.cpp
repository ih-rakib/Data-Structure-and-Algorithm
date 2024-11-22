// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;

        int n = matrix.size(), m = matrix[0].size();

        for(int i = 0; i < n; ++i) {
            string pattern = "";
            for(int j = 0; j < m; ++j) {
                pattern += (matrix[i][j] == matrix[i][0] ? '1' : '0');
            }
            patternCount[pattern]++;
        }

        int ans = 0; // same rows

        for(auto x : patternCount) {
            ans = max(ans, x.second);
        }
        
        return ans;
    }
};

// Author: Ikramul Hasan Rakib