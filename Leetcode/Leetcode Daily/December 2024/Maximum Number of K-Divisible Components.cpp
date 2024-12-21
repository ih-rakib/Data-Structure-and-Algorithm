// https://leetcode.com/problems/maximum-number-of-k-divisible-components/

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Initialize visited array and components counter
        vector<bool> visited(n, false);
        int components = 0;

        // Step 3: Define DFS function
        function<long long(int)> dfs = [&](int node) {
            visited[node] = true;
            long long subtree_sum = values[node]; 

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    long long child_sum = dfs(neighbor);
                    // If child sum is divisible by k, count it as a separate component
                    if (child_sum % k == 0) {
                        components++;
                    } else {
                        // Otherwise, add it to the current subtree
                        subtree_sum += child_sum;
                    }
                }
            }

            return subtree_sum;
        };

        // Step 4: Start DFS from node 0
        long long total_sum = dfs(0);

        // If the total sum is divisible by k, the root itself is a valid component
        if (total_sum % k == 0) {
            components++;
        }

        return components;
    }
};


// Author: Ikramul Hasan Rakib