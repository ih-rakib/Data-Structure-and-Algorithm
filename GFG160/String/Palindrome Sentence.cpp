// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/string-palindromic-ignoring-spaces4723

class Solution {
  public:
    bool sentencePalindrome(string &s) {
        string t;

        for(char c : s) {
            if(isalnum(c)) {
                t += tolower(c);
            }
        }
        return t == string(t.rbegin(), t.rend());
    }
};

// Author: Ikramul Hasan Rakib