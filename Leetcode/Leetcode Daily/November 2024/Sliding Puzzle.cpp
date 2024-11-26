// https://leetcode.com/problems/sliding-puzzle/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = ""; // starting state

        for(auto &row : board) {
            for(int &num : row) {
                start += to_string(num);
            }
        }

        string target = "123450"; // target state to reach

        vector<vector<int>> neighbors = {
            {1, 3}, {0, 2, 4}, {1, 5},
            {0, 4}, {1, 3, 5}, {2, 4}
        };

        queue<pair<string, int> > q; // (state, pos of 0)
        unordered_set<string> vis; // to track visited states

        q.push({start, start.find('0')});
        vis.insert(start);

        int moves = 0;
        while(!q.empty()) {
            int n = q.size(); // process all states in current level
            while(n--) {
                auto [state, zero] = q.front(); // zero: index/pos of 0
                q.pop();

                // process current state
                if(state == target) {
                    return moves;
                }

                // add neighbors to queue
                for(auto &neighbor : neighbors[zero]) {
                    string new_state = state; // to not permanently modify the state
                    swap(new_state[zero], new_state[neighbor]);

                    if(!vis.count(new_state)) {
                        vis.insert(new_state);
                        q.push({new_state, neighbor});
                    } 
                }
            }
            moves++;
        }
        return -1;
    }
};


// Author: Ikramul Hasan Rakib