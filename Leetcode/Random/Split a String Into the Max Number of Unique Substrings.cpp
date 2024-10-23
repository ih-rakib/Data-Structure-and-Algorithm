// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return solve(s, 0, seen);
    }

    int solve(string &s, int start, unordered_set<string> &seen) {
        if(start == s.length()) {
            return 0; // reached at the end of string: base case
        }

        int ans = 0;
        string cur = "";

        for(int i = start; i < s.length(); ++i) {
            cur += s[i];

            if(seen.find(cur) == seen.end()) {
                seen.insert(cur);
                ans = max(ans, 1 + solve(s, i + 1, seen));
                seen.erase(cur); // backtrack
            }
        }
        return ans;
    }
};