// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/kadanes-algorithm-1587115620

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int ans = INT_MIN, prev = 0;

        for(int i = 0; i < arr.size(); ++i) {
            if(prev + arr[i] >= arr[i]) {
                prev = prev + arr[i];
            }else {
                prev = arr[i];
            }
            ans = max(ans, prev);
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib