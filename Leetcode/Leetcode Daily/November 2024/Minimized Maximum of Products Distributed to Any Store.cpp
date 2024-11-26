// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

class Solution {
public:
    bool ok(int n, vector<int> &quantities, int x) { // if x products can be distributed to n store
        long long storeNeeded = 0;

        for(auto &quantity : quantities) {
            storeNeeded += 1LL * (quantity + x - 1) / x; // x product need 1 store, quantity product need quantity / x store
            if(storeNeeded > n) return false;
        }
        return storeNeeded <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = *max_element(quantities.begin(), quantities.end());
        int ans = r;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(ok(n, quantities, mid)) {
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