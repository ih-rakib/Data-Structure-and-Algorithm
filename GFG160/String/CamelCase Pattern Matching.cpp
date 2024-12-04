// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/camelcase-pattern-matching2259

class Solution {
  public:
    vector<string> camelCase(vector<string> &arr, string &pat) {
        vector<string> ans;

        for(string w : arr) {
            string s;
            for(char c : w) {
                if(isupper(c)) {
                    s += c;
                }
            }

            if(s.substr(0, pat.size()) == pat) {
                ans.push_back(w);
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib