// https://leetcode.com/problems/find-champion-ii/

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in_degree(n, 0);

        for(auto &edge : edges) {
            int u = edge[0], v = edge[1];
            in_degree[v]++;
        }

        // find nodes with in_degree = 0

        int ans = -1, cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(in_degree[i] == 0) {
                cnt++;
                ans = i;
            }
        }
        return (cnt > 1 ? -1 : ans);
    }
};

// Author: Ikramul Hasan Rakib

/*

    [a -> b] : a is stronger than b
    team 'x' will be champion if no edge coming towards 'x' meaning in_degree[x] = 0
    if multiple node have in_degree = 0, no unique champion : return -1

*/