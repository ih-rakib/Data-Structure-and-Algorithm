// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;
        int row = 0, col = m - 1;

        while(row < n and col >= 0) {
            if(grid[row][col] < 0) {
                res += (n - row); // // If the current element is negative, count all elements below in the same column are negative
                col--;
            }else {
                row++;
            }
        }
        
        return res;
    }
};

/*

// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                res += (grid[i][j] < 0);
            }
        }
        return res;
    }
};

*/