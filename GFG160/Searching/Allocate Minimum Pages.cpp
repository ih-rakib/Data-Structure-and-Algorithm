// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/allocate-minimum-number-of-pages0937

class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();

        if(k > n) return -1;

        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        int ans = r;

        auto ok = [&](int x) {
            int curPage = 0, student = 1;

            for(int page : arr) {
                if(curPage + page > x) {
                    student++;
                    curPage = page;
                    if(student > k) return false;
                }else {
                    curPage += page;
                }
            }
            return true;
        };

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(ok(mid)) {
                ans = mid;
                r = mid - 1; // to minimize
            }else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib