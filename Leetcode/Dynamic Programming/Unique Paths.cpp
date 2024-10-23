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

/*

always total moves: m - 1 down move + n - 1 right move so total = m - 1 + n - 1 = m + n - 2
k=min(m−1,n−1)
total = m + n - 2;
res = C(total, k) or C(total, total - k)

               N!
C(N, K) = -----------
           K! (N - K)!

            N x (N-1) x (N-2) x .....(N-K+1)
       =  ------------------------------------  N: total, K: option
            K x (K-1) x (K-2) x .........x 1    

*/