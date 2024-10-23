// https://leetcode.com/problems/n-th-tribonacci-number/

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 or n == 2) return 1;

        vector<int> dp(n+1);

        for(int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
};