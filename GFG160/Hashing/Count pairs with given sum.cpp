// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/count-pairs-with-given-sum--150253

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < arr.size(); ++i) {
            int x = target - arr[i];
            ans += mp[x];
            mp[arr[i]]++;
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib