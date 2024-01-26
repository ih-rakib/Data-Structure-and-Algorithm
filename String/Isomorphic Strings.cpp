// Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> cs, ct;

        for(int i = 0; i < s.length(); ++i){
            if((cs[s[i]] and cs[s[i]] != t[i]) or (ct[t[i]] and ct[t[i]] != s[i])) return false;
            cs[s[i]] = t[i];
            ct[t[i]] = s[i];
        }
        return true;
    }
};


// Author: Ikramul Hasan Rakib