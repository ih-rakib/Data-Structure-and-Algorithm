// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/max-circular-subarray-sum-1587115620

class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
        int total = 0, mxSum = INT_MIN, mnSum = INT_MAX, curMax = 0, curMin = 0;
        
        for(int x : arr) {
            total += x;

            curMax = max(x, x + curMax);
            mxSum = max(mxSum, curMax);
            
            curMin = min(x, x + curMin);
            mnSum = min(mnSum, curMin);
        }

        int cirCularSum = total - mnSum;

        return (mxSum < 0 ? mxSum : max(mxSum, cirCularSum));
    }
};

// Author: Ikramul Hasan Rakib