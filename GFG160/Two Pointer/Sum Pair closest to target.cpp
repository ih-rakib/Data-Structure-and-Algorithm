// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/pair-in-array-whose-sum-is-closest-to-x1124

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if(n < 2) return {};
        vector<int> res;
        int closestDiff = INT_MAX;
        int maxAbsDiff = INT_MIN;
        
        int l = 0, r = n - 1;
        while(l < r) {
            int sum = arr[l] + arr[r];
            int diff = target - sum;
            
            if(abs(diff) < closestDiff or (abs(diff) == closestDiff and 
            abs(arr[r] - arr[l]) > maxAbsDiff)) {
                closestDiff = abs(diff);
                maxAbsDiff = abs(arr[r] - arr[l]);
                res = {arr[l], arr[r]};
            }
            
            if(sum < target) {
                l++;
            }else {
                r--;
            }
        }
        return res;
    }
};

// Author: Ikramul Hasan Rakib