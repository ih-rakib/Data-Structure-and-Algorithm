// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/aggressive-cows

class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int l = 0, r = stalls.back() - stalls.front();

        int ans = 0;

        auto ok = [&] (int mid) {
            int cnt = 1;
            int lastPos = stalls[0];

            for(int i = 1; i < stalls.size(); ++i) {
                if(stalls[i] - lastPos >= mid) {
                    cnt++;
                    lastPos = stalls[i];
                    if(cnt == k) return true;
                }
            }
            return false;
        };

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(ok(mid)) {
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