// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

class Solution {
public:
    char findKthBit(int n, int k) {
        return solve(n, k);
    }

    char solve(int n, int k) {
        if(n == 1) return '0';

        int len = (1 << n) - 1;
        int mid = (len + 1) / 2;

        if(k == mid) return '1';
        else if(k < mid) {
            return solve(n - 1, k);
        }else {
            int mirrorPos = len - k + 1;
            char mirrorBit = solve(n - 1, mirrorPos);
            return mirrorBit == '0' ? '1' : '0';
        }
    }
};

/*

s(n) = s(n-1) + '1' + reverse(invert(s(n-1)))

s1 = 1
s2 = 3
s3 = 7
s4 = 15

len = 2^n - 1
so, len is odd

mid = (2^n - 1 + 1) / 2 = 2^(n-1) or (len + 1) / 2
if k = mid: bit is just '1'
if k lies in first half -> check for bit in first half
otherwise -> find the mirror position of bit in first half (as it's symmetric (but inverse))
mirrorPos = len - k + 1
find bit for mirrorPos, finally invert the bit cause it was inverted originally

*/