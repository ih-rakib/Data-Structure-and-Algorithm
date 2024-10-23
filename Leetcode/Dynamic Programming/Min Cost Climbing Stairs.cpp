class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        if (n == 1) return cost[0];

        // dp[i] represents the minimum cost to reach step i
        vector<int> dp(n+1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; ++i) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        // To reach the top, we can either come from the last or second last step
        return min(dp[n-1], dp[n-2]);
    }
};
