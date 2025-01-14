// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/equilibrium-point-1587115620

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        
        int total = accumulate(arr.begin(), arr.end(), 0);
        int left = 0;
        for(int i = 0; i < n; ++i) {
            if(left == total - left - arr[i]) {
                return i;
            }
            left += arr[i];
        }
        return -1;
    }
};

// Author: Ikramul Hasan Rakib