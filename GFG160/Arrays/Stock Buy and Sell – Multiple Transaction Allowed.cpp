// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/stock-buy-and-sell2615

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();

        if(n < 2) return 0; 

        int ans = 0;
        for(int i = 1; i < n; ++i) {
            if(prices[i] > prices[i-1]) {
                ans += (prices[i] - prices[i-1]);
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib