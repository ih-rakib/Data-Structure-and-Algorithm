// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-bonus-problems/problem/square-root

class Solution {
  public:
    int floorSqrt(int n) {
        // return sqrt(n);

        if(n <= 1) return 1;

        int l = 1, r = n, ans = 0;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            // mid * mid = n -> mid = n/mid
            if(mid <= n/mid) {
                ans = mid;
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib