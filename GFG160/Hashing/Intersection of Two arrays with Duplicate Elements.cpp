// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/intersection-of-two-arrays-with-duplicate-elements

class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for(int x : a) mp[x] = 1;
        for(int x : b) {
            if(mp.count(x)) {
                ans.push_back(x);
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

// Author: Ikramul Hasan Rakib