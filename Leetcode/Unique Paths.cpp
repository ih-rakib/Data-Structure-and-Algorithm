// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalMoves = m + n - 2;
        int k = min(m - 1, n - 1);
        long long result = 1;

        for(int i = 1; i <= k; ++i) {
            result *= (totalMoves - k + i);
            result /= i;
        }
        return (int)result;
    }
};