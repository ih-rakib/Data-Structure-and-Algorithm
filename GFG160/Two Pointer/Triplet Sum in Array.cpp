// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-bonus-problems/problem/triplet-sum-in-array-1587115621

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        if(n < 3) return false;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i + 2 < n; ++i) {
            int l = i + 1, r = n - 1;
            
            while(l < r) {
                int sum = arr[l] + arr[r] + arr[i];
                
                if(sum == target) {
                    return true;
                }else if(sum < target) {
                    l++;
                }else {
                    r--;
                }
            }
        }
        return false;
    }
};

// Author: Ikramul Hasan Rakib