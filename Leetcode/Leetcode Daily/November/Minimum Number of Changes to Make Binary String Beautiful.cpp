// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int ans = 0;

        for(int i = 1; i < n; i += 2) {
            ans += (s[i] != s[i-1]);
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib