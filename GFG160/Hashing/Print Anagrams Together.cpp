// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/print-anagrams-together

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> mp;
        vector<string> ordered;
        for(string &s : arr) {
            string cur = s;
            sort(cur.begin(), cur.end());
            if(mp.find(cur) == mp.end()) {
                ordered.push_back(cur);
            }
            mp[cur].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto &z : ordered) {
            auto x = mp[z];
            ans.push_back(x);
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib