// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> vis(n , vector<bool>(m, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        pq.push({0, {0, 0}}); // {time, {row, col}}

        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();

            int r = pos.first, c = pos.second;

            if (r == n - 1 && c == m - 1) {
                return time;
            }

            if (vis[r][c]) continue;
            
            vis[r][c] = true;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                    bool wait = (grid[nr][nc] - time) % 2 == 0; // even: 1, odd: 0
                    int nt = max(grid[nr][nc] + wait, time + 1);
                    pq.push({nt, {nr, nc}});
                }
            }
        }
        return -1;
    }
};

// Author: Ikramul Hasan Rakib