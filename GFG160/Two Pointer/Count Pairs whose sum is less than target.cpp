// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-pairs-whose-sum-is-less-than-target

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int l = 0, r = n - 1;
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        while(l < r) {
            int x = arr[l] + arr[r];
            if(x < target) {
                ans += (r - l);
                l++;
            }else {
                r--;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib