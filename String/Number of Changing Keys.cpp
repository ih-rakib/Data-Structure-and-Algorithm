// Number of Changing Keys
// https://leetcode.com/contest/weekly-contest-382/problems/number-of-changing-keys/

class Solution {
public:
    int countKeyChanges(string s) {
        int n = s.length(), ans = 0;
        for(int i = 0; i < n; ++i){
            if(isupper(s[i])) s[i] = tolower(s[i]);
            if(i and s[i]!=s[i-1]) ans++;
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib