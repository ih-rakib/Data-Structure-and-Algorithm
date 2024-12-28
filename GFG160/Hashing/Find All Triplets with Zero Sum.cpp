// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/find-all-triplets-with-zero-sum

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n; ++i) {
            unordered_map<int, vector<int>> mp;

            for(int j = i + 1; j < n; ++j) {
                int need = -arr[i] - arr[j];

                if(mp.find(need) != mp.end()){
                    for(int x : mp[need]) {
                        vector<int> triplet = {x, j, i};
                        sort(triplet.begin(), triplet.end());
                        ans.push_back(triplet);
                    }
                }
                
                mp[arr[j]].push_back(j);
            }
        }

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

// Author: Ikramul Hasan Rakib