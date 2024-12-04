// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/longest-prefix-suffix2527

class Solution {
  public:
    int longestPrefixSuffix(string &s) {
        int n = s.length();

        vector<int> lps(n, 0);

        int len = 0, i = 1;

        while(i < n) {
            if(s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }else {
                if(len != 0) {
                    len = lps[len - 1];
                }else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps[n-1];
    }
};

// Author: Ikramul Hasan Rakib