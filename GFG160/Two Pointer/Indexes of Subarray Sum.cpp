// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/subarray-with-given-sum-1587115621

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int cur = 0, l = 0;
        
        for(int r = 0; r < n; ++r) {
            cur += arr[r];
            
            while(l <= r and cur > target) {
                cur -= arr[l];
                l++;
            }
            
            if(cur == target) {
                return {l+1, r+1};
            }
        }
        return {-1};
    }
};

// Author: Ikramul Hasan Rakib