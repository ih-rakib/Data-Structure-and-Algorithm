// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/search-pattern0205

class Solution {
  public:

   vector<int> search(string& pat, string& txt) {
        int n = txt.length(), m = pat.length();

        vector<int> ans;
        
        for(int i = 0; i + m - 1 < n ; ++i) {
            if(txt[i] == pat[0]) {
                if(txt.substr(i, m) == pat) ans.push_back(i);
            }
        }
        
        return ans;
    }
    // vector<int> search(string& pat, string& txt) {
    //     int n = txt.length(), m = pat.length();

    //     vector<int> lps(m, 0);
    //     vector<int> ans;

    //     int i = 1, len = 0;
    //     while(i < m) {
    //         if(pat[len] == pat[i]) {
    //             lps[i] = len + 1;
    //             len++; i++;
    //         }else {
    //             if(len != 0) {
    //                 len = lps[len - 1];
    //             }else {
    //                 lps[i] = 0;
    //                 i++;
    //             }
    //         }
    //     }

    //     i = 0, len = 0;
    //     while(i < n) {
    //         if(txt[i] == pat[len]) {
    //             len++; i++;
    //         }
    //         if(len == m) {
    //             ans.push_back(i - len);
    //             len = lps[len - 1];
    //         }else if(i < n and txt[i] != pat[len]) {
    //             if(len != 0) {
    //                 len = lps[len - 1];
    //             }else {
    //                 i++;
    //             }
    //         }
    //     }
    //     return ans;
    // }
};

// Author: Ikramul Hasan Rakib