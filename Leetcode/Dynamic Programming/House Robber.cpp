// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i-1], nums[i-1]+dp[i-2]);
        }
        return dp[n];
    }
};

// dp[i] : maximum amount of money that can be robbed from the first i houses.

/*

// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int prev1 = 0, prev2 = 0;

        for(int i = 0; i < n; ++i) { // prev1: dp[i-1], prev2: dp[i-2]
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

// dp[i] : maximum amount of money that can be robbed from the first i houses.


*/