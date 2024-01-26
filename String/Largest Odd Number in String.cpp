// Largest Odd Number in String
// https://leetcode.com/problems/largest-odd-number-in-string/

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();

        for(int i = n-1; i >= 0; --i) {
            int cur = num[i] - '0';
            if(cur & 1) {
                return num;
            }else {
                num.pop_back();
            }
        }
        return num;
    }
};


// Author: Ikramul Hasan Rakib