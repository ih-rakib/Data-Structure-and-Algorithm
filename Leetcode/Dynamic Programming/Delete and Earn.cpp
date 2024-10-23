// https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> freq;

        int mx = INT_MIN;

        for(auto &x : nums) {
            freq[x]++;
            mx = max(mx, x);
        }

        vector<int> dp(mx+1, 0);

        for(int i = 1; i <= mx; ++i) {
            int points = i * freq[i]; // point we can earn by taking i
            dp[i] = max(dp[i-1], (i > 2 ? dp[i-2] : 0) + points);
        }
        return dp[mx];
    }
};

// dp[i] = max # of points we can earn by using numbers from 0 to i
// dp[i-1] : we do not take i, so ans stays as ans till i - 1 (dp[i-1])
// dp[i-2] + points : earn points i * freq[i] by taking i + as we take i, we can't take i-1, cause i - 1 will be erased(question) 