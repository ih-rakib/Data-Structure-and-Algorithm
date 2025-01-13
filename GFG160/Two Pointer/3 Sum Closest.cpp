// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-bonus-problems/problem/3-sum-closest

class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        int n = arr.size();
        if(n < 3) return false;
        
        sort(arr.begin(), arr.end());
        
        int close = INT_MIN;
        
        for(int i = 0; i + 2 < n; ++i) {
            int l = i + 1, r = n - 1;
            
            while(l < r) {
                int cur = arr[l] + arr[r] + arr[i];
                
                if(abs(cur - target) < abs(close - target) or 
                (abs(cur - target) == abs(close - target) and cur > close)) {
                    close = cur;
                }
                
                if(cur < target) {
                    l++;
                }else {
                    r--;
                }
            }
        }
        return close;
    }
};

// Author: Ikramul Hasan Rakib