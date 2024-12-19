// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-bonus-problems/problem/square-root

class Solution {
  public:
    int kokoEat(vector<int>& arr, int h) { // h: hours
        int n = arr.size();

        int l = 1, r = *max_element(arr.begin(), arr.end());
        int ans = r;

        auto ok = [&](int s) {
            long long hour = 0;

            for(int pile : arr) {
                hour += (pile + s - 1) / s; // ceil(pile/s)
            }
            return hour <= h;
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