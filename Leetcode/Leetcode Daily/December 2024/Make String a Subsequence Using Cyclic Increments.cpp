// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        int i = 0;
        
        for(char c : str1) {
            if(i < m and (str2[i] - c + 26) % 26 <= 1) i++;
        }
        return i == m;
    }
};

// Author: Ikramul Hasan Rakib