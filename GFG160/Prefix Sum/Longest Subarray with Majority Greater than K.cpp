// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-bonus-problem/problem/longest-subarray-with-majority-greater-than-k

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> pmap;
        
        int psum = 0, ans = 0;
        for(int i = 0; i < n; ++i) {
            if(arr[i] > k) {
                psum += 1;
            }else {
                psum -= 1;
            }
            
            if(psum > 0) {
                ans = i + 1;
            }
            
            if(pmap.find(psum - 1) != pmap.end()) {
                ans = max(ans, i - pmap[psum - 1]);
            }
            
            if(pmap.find(psum) == pmap.end()) {
                pmap[psum] = i;
            }
        }
        return ans;
    }
};


// Author: Ikramul Hasan Rakib