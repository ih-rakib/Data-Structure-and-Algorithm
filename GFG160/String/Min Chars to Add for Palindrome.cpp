// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/minimum-characters-to-be-added-at-front-to-make-string-palindrome

class Solution {
  public:
    int minChar(string& s) {
        int n = s.length();

        string r = s;
        reverse(r.begin(), r.end());
        string z = s + '#' + r;

        vector<int> lps(z.size(), 0);

        int len = 0, i = 1;

        while(i < z.size()) {
            if(z[i] == z[len]) {
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
        return n - lps.back();
    }
};

// Author: Ikramul Hasan Rakib