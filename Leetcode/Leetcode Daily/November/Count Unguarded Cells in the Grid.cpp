// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char> > grid(m, vector<char> (n, 'u')); // assume all are unoccupied initially

        // mark walls
        for(auto &wall : walls) {
            grid[wall[0]][wall[1]] = 'w';
        }

        // mark guard
        for(auto &guard : guards) {
            grid[guard[0]][guard[1]] = 'g';
        }

        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};

        for(auto &guard : guards) {
            for(auto &dir : directions) {
                int x = guard[0];
                int y = guard[1];

                while(true) {
                    x += dir.first;
                    y += dir.second;

                    // stop is out of bounds
                    if(x < 0 or x >= m or y < 0 or y >= n or grid[x][y] == 'w' or grid[x][y] == 'g') {
                        break;
                    }

                    // mark as guarded otherwise
                    if(grid[x][y] == 'u') {
                        grid[x][y] = 'v'; // v : visible
                    }
                }
            }
        }

        int unguarded = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 'u') unguarded++;
            }
        }

        return unguarded;
    }
};

// Author: Ikramul Hasan Rakib