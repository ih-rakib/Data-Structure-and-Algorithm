// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;

        vector<vector<int> > adj(n);

        for(int i = 0; i + 1 < n; ++i) {
            adj[i].push_back(i+1);
        }

        auto bfs = [&]() {
            vector<int> dist(n, -1);
            dist[0] = 0;
            queue<int> q;
            q.push(0); // starting city 0

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(int x : adj[node]) {
                    if(dist[x] == -1) {
                        dist[x] = dist[node] + 1;
                        q.push(x);
                    }
                }
            }
            return dist[n-1];
        };

        for(auto &query : queries) {
            int u = query[0], v = query[1];
            adj[u].push_back(v);

            int shortest = bfs();
            ans.push_back(shortest);
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib