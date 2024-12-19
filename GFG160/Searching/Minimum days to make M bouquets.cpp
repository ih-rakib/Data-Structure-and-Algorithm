// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-bonus-problems/problem/square-root

class Solution {
  public:
    int minDaysBloom(int m, int k, vector<int> &arr) {
        int l = *min_element(arr.begin(), arr.end());
        int r = *max_element(arr.begin(), arr.end());
        int ans = -1;

        auto ok = [&](int day) {
            int cnt = 0, flowers = 0;

            for(int i = 0; i < arr.size(); ++i) {
                if(arr[i] <= day) {
                    flowers++;
                    if(flowers == k) { // make a bouquet
                        cnt++;
                        flowers = 0; // reset for new bouquet
                    }
                }else {
                    flowers = 0; // not bloomed yet
                }
            }
            return cnt >= m;
        };

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(ok(mid)) {
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