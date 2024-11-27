// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/repetitive-addition-of-digits2221

class Solution {
  public:
    int singleDigit(int n) {
        if(n == 0) return 0;
        if(n % 9 == 0) return 9;
        return n % 9;
    }
};

// Author: Ikramul Hasan Rakib

/*

    digit root

*/