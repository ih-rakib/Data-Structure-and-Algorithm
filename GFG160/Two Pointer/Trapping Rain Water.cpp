// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/trapping-rain-water-1587115621

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        int lmx = 0, rmx = 0, ans = 0;
        
        while(l < r) {
            if(arr[l] < arr[r]) {
                lmx = max(lmx, arr[l]);
                ans += (lmx - arr[l]);
                l++;
            }else {
                rmx = max(rmx, arr[r]);
                ans += (rmx - arr[r]);
                r--;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib