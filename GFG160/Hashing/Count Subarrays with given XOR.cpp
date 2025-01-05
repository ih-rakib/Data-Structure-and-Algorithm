// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/count-subarray-with-given-xor

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> pref;
        pref[0] = 1;
        
        int cur = 0, ans = 0;
        for(int x : arr) {
            cur ^= x;
            ans += pref[cur ^ k];
            pref[cur]++;
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib