// https://leetcode.com/problems/minimum-total-distance-traveled/

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        
        dp[0][0] = 0;

        for (int j = 1; j <= m; ++j) {
            dp[0][j] = 0;

            for (int i = 1; i <= n; ++i) {
                dp[i][j] = dp[i][j - 1];

                long long dist = 0;

                for (int k = 1; k <= min(factory[j - 1][1], i); ++k) {
                    dist += abs(robot[i - k] - factory[j - 1][0]);
                    if(dp[i - k][j - 1] < LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + dist);
                    }
                }
            }
        }
        return dp[n][m];
    }
};

/*

dp[i][j] = minimum distance required to repair first i robot using first j factory

Complexity:
    Time Complexity: O(n x m x factory limit)
    Space Complexity: O(n x m)

Steps:

1. Sort the robot positions and factory positions to handle them in order of distance.
2. dp[i][j] = minimum distance required to repair the first i robots using the first j factories.
3. dp[0][0] = 0 -> no robot to repair
4. For each factory (j from 1 to m), dp[0][j] = 0 -> no robot to repair
5. For each robot (i from 1 to n), dp[i][j] = dp[i][j-1] -> ignoring current factory initially
6. For each k from 1 to min(factory[j-1][1], i): 
    -> try to assign k robots to current factory
    -> factory[j-1][1] = capacity(limit) of factory
    -> i = number of remaining robots
7. dist += abs(robot[i-k] - factory[j-1][0]);
   dp[i][j] = min(dp[i][j], dp[i-k][j-1] + dist);

   -> robot[i-k] = positon of the (i-k)th robot
   -> factory[j-1][0] - position or the current factory 
   -> dist = additional cost to send last k robot to the current factory 
   -> dp[i-k][j-1] = min distance required to repair first(previous) [i-k] robot using first [j-1] factory
8. return dp[n][m] = minimum cost to repair all robots using all factories

*/

// Author: Ikramul Hasan Rakib