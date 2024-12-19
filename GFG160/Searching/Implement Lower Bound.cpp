// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-bonus-problems/problem/implement-lower-bound

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0, r = n - 1, ans = n;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(arr[mid] >= target) {
                ans = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib