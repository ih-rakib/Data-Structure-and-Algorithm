// Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string s = strs[0], t = strs[n-1];
        int a = s.length(), b = t.length();
        string res = "";
        for(int i = 0; i < min(a, b); ++i) {
            if(s[i] == t[i]) res += s[i];
            else break;
        }
        return res;
    }
};

// Author: Ikramul Hasan Rakib