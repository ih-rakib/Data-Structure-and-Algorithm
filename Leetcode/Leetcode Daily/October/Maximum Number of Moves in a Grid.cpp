// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/

class Solution {
public:
    int n, m;
    vector<vector<int> > dp;
    vector<vector<int> > dirs = {{-1,1}, {0,1}, {1,1}};

    int dfs(vector<vector<int>> &grid, int row, int col) {
        if(dp[row][col] != -1) return dp[row][col];

        int maxMoves = 0;

        for(auto dir : dirs) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if(newRow >= 0 and newRow < n and newCol >= 0 and newCol < m and grid[newRow][newCol] > grid[row][col]) {
                maxMoves = max(maxMoves, 1 + dfs(grid, newRow, newCol));
            }
        }
        dp[row][col] = maxMoves;
        return maxMoves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp = vector<vector<int>> (n, vector<int> (m, -1));

        int ans = 0;

        for(int i = 0; i < n; ++i) {
            // start dfs from each cell in first column
            ans = max(ans, dfs(grid, i, 0));
        }
        return ans;
    }
};