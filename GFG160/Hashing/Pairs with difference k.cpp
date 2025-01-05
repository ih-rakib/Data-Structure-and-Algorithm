// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-bonus-problem/problem/pairs-with-difference-k1713

class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairs(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int ans = 0;
        for(int x : arr) {
            ans += freq[x - k];
            ans += freq[x + k];
            freq[x]++;
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib