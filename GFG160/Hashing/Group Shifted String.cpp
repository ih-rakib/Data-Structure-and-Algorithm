// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-bonus-problem/problem/group-shifted-string

class Solution {
  public:
    vector<vector<string>> groupShiftedString(vector<string> &arr) {
        unordered_map<string, vector<string>> group;
        
        auto f = [](string &s) {
            string n = "";
            for(int i = 1; i < s.length(); ++i) {
                int shift = (s[i] - s[i-1] + 26) % 26;
                n += char(shift + 'a');
            }
            return n;
        };
        
        for(auto &s : arr) {
            string n = f(s);
            group[n].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto &g: group) {
            ans.push_back(g.second);
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib