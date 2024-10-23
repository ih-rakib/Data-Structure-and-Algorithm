// https://leetcode.com/problems/unique-paths-iii/

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int startRow, startCol, emptyCount = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }

                if(grid[i][j] == 0) {
                    emptyCount++;
                }
            }
        }

        return backtrack(grid, startRow, startCol, emptyCount);
    }

    private:
        int backtrack(vector<vector<int> > &grid, int row, int col, int emptyCount) {
            int n = grid.size();
            int m = grid[0].size();

            if(row < 0 or row >= n or col < 0 or col >= m or grid[row][col] == -1) {
                return 0;
            }

            if(grid[row][col] == 2) { // we have reached the ending square
                // check if we have visited all the empty square - meaning emptyCount will become 0
                return emptyCount == 0 ? 1 : 0;
            }

            int temp = grid[row][col];
            grid[row][col] = -1; // mark as visited

            // explore all 4 direction
            int totalPaths = backtrack(grid, row+1, col, temp == 0 ? emptyCount - 1 : emptyCount) + 
                             backtrack(grid, row-1, col, temp == 0 ? emptyCount - 1 : emptyCount) + 
                             backtrack(grid, row, col+1, temp == 0 ? emptyCount - 1 : emptyCount) + 
                             backtrack(grid, row, col-1, temp == 0 ? emptyCount - 1 : emptyCount);

            // Backtrack: unmark the cell
            grid[row][col] = temp;

            return totalPaths;
        }
};