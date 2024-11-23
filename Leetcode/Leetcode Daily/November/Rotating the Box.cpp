// https://leetcode.com/problems/rotating-the-box/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));

        for (int i = 0; i < n; ++i) {
            int empty = m - 1;
            for (int j = m - 1; j >= 0; --j) {
                if (box[i][j] == '.') continue;
                if (box[i][j] == '#') {
                    ans[empty][n - i - 1] = '#';
                    empty--;
                } else { // '*'
                    ans[j][n - i - 1] = '*';
                    empty = j - 1; 
                }
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib