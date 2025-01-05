// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-bonus-problem/problem/min-subsets-with-consecutive-numbers0601

class Solution {
  public:
    int numOfSubset(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        
        int ans = 1;
        for(int i = 1; i < arr.size(); ++i) {
            if(arr[i] != arr[i-1] + 1) ans++;
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib