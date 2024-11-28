// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<> > pq; // {cost, {x, y}} : cost to reach cell(x, y) removing obstacles

        vector<vector<int>> minCost(n, vector<int> (m, INT_MAX)); // minCost[i][j]: min # of obstacles removed to reach cell(i, j) 
        minCost[0][0] = 0;

        vector<pair<int, int> > dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            auto [curCost, pos] = pq.top();
            pq.pop();

            int x = pos.first, y = pos.second;

            if(x == n - 1 && y == m - 1) return curCost;
            if(curCost > minCost[x][y]) continue;

            for(auto [dx, dy]: dirs) {
                int nx = x + dx, ny = y + dy;

                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newCost = curCost + grid[nx][ny];

                    if(newCost < minCost[nx][ny]) {
                        minCost[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }
        
        return -1;
    }
};

// Author: Ikramul Hasan Rakib

/*
    pq: process cell where cost is minimum first
    minCost: minimum cost to reach each cell
*/