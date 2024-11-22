// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/buy-stock-2

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        if(prices.empty()) return 0;

        int n = prices.size();
        int minPrice = prices[0];
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            ans = max(ans, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib