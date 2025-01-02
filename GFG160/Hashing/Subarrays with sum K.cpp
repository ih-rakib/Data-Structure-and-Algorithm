// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/subarrays-with-sum-k

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> pref;
        pref[0] = 1;
        
        int ans = 0, cur = 0;
        for(int x : arr) {
            cur += x;
            ans += pref[cur - k];
            pref[cur]++;
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib