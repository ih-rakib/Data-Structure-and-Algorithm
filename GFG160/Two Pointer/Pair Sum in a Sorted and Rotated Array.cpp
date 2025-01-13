// Problem: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-bonus-problems/problem/pair-sum-in-a-sorted-and-rotated-array

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        int n = arr.size();
        if(n < 2) return false;
        
        int pivot = 0;
        
        for(int i = 0; i + 1 < n; ++i) {
            if(arr[i] > arr[i+1]) {
                pivot = i + 1; break;
            }
        }
        
        int lo = pivot, hi = (pivot - 1 + n) % n;
        
        while(lo != hi) {
            int sum = arr[lo] + arr[hi];
            
            if(sum == target) return true;
            else if(sum < target) {
                lo = (lo + 1) % n;
            }else {
                hi = (hi - 1 + n) % n;
            }
        }
        return false;
    }
};

// Author: Ikramul Hasan Rakib