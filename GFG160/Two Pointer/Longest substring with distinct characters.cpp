// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/longest-distinct-characters-in-string5848

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.length();
        int l = 0, r = 0, ans = 0;
        unordered_set<char> st;
        while(r < n) {
            while(st.find(s[r]) != st.end()) {
                st.erase(s[l]);
                l++;
            }
            
            st.insert(s[r]);
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib