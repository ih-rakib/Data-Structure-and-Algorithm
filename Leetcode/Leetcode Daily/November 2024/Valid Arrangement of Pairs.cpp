// https://leetcode.com/problems/valid-arrangement-of-pairs/

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int> > graph;
        unordered_map<int, int> in_degree, out_degree;

        // build graph and degree maps
        for(auto &pair : pairs) {
            int s = pair[0], e = pair[1];
            in_degree[e]++; 
            out_degree[s]++;
            graph[s].push_back(e);
        }

        // find starting point
        int start = pairs[0][0];
        for(auto& [node, _] : graph) {
            if(out_degree[node] - in_degree[node] == 1) {
                start = node; 
                break;
            }
        }

        // Hierholzer's Algorithm: find Eulerian path
        vector<int> path;
        stack<int> st;
        st.push(start);

        while(!st.empty()) {
            int node = st.top();
            if(!graph[node].empty()) {
                int next = graph[node].front();
                graph[node].pop_front();
                st.push(next);
            }else {
                path.push_back(node);
                st.pop();
            }
        }

        reverse(path.begin(), path.end());

        // path construction(pairs)
        vector<vector<int> > res;

        for(int i = 0; i + 1 < path.size(); ++i) {
            res.push_back({path[i], path[i+1]});
        }
        
        return res;
    }
};

// Author: Ikramul Hasan Rakib

/*

    Eulerian Path: Visits all edges exactly once. 
        at most one node have: 
        -> out_degree - in_degree = 1 : starting point
        -> in_degree - out_degree = 1 : ending point
        rest: in_degree = out_degree
    Start Node Selection: If all nodes have equal in-degree and out-degree, start with any node.
    Path Reconstruction: Use a stack to traverse edges and backtrack when necessary.
    Hierholzer's Algorithm



    Input: pairs = [[1, 2], [2, 3], [3, 4], [4, 5], [2, 4], [1, 3]]
    graph: {
        1: [2, 3], 
        2: [3, 4], 
        3: [4], 
        4: [5]
    }

    in_degree: {
        2: 2, 
        3: 2, 
        4: 2, 
        5: 1, 
        1: 0
    }

    out_degree: {
        1: 2, 
        2: 2, 
        3: 1, 
        4: 1
    }

    starting point: 1

    - stack: {1}, {1,2}, {1,2,3}, {1,2,3,4}, {1,2,3,4,5}
    - path: {5}, {5,4}, {5,4,3}, {5,4,3,1}, {5,4,3,2,1}
    
    - reverse: {1,2,3,4,5}

*/