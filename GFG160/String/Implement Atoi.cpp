// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/implement-atoi

class Solution {
  public:
    int myAtoi(char *s) {
        // skip whitespaces
        int i = 0, sign = 1;

        while(s[i] == ' ') i++;

        // check for sign
        if(s[i] == '-' or s[i] == '+') {
            sign = (sign = '-') ? -1 : 1;
            i++;
        }

        long long res = 0;
        while(s[i] >= '0' and s[i] <= '9') {
            res = (res * 10) + (s[i] - '0');
            if(sign * res > INT_MAX) return INT_MAX;
            if(sign * res < INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(sign * res);
    }
};

// Author: Ikramul Hasan Rakib