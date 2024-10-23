// https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        int prev1 = 0;
        int prev2 = 1;

        for(int i = 2; i <= n; ++i){
            int cur = prev1 + prev2;
            prev1 = prev2;
            prev2 = cur;
        }
        return prev2;
    }
};


/*


// https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1);

        if(n <= 1) return n;
        
        dp[0] = 0;
        dp[1] = 1; 

        for(int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

*/