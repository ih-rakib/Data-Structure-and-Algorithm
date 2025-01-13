// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-bonus-problems/problem/minimum-removals-for-target-sum

class Solution {
  public:
    int minRemovals(vector<int> &arr, int k) {
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(), 0);
        
        if(k > total) return -1;
        
        int target = total - k;
        
        int l = 0, cur = 0, mx = -1;
        
        for(int r = 0; r < n; ++r) {
            cur += arr[r];
            
            while(cur > target and l <= r) {
                cur -= arr[l];
                l++;
            }
            
            if(cur == target) {
                mx = max(mx, r - l + 1);
            }
        }
        return (mx == -1 ? -1 : n - mx);
    }
};

// Author: Ikramul Hasan Rakib