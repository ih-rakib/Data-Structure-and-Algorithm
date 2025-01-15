// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/longest-sub-array-with-sum-k0809

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0, ans = 0;
        unordered_map<int, int> psum;
        
        for(int i = 0; i < n; ++i) {
            sum += arr[i];
            
            if(sum == k) {
                ans = i + 1;
            }
            
            if(psum.find(sum - k) != psum.end()) {
                ans = max(ans, i - psum[sum - k]);
            }
            
            if(psum.find(sum) == psum.end()) {
                psum[sum] = i;   
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib