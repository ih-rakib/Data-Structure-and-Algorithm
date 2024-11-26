// https://leetcode.com/problems/minimum-array-end/

class Solution {
public:
    long long minEnd(int n, int x) {
        long long cur = x;
        n--;
        while(n--) {
            cur = (cur + 1) | x;
        }
        return cur;
    }
};

// Author: Ikramul Hasan Rakib

/*

    i have to keep set bits of x sticky. 
    so each time i am doing or with x.
    cur + 1 as it's the next min greater number.

*/