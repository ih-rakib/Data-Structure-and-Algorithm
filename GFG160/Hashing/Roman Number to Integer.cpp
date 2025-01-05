// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-bonus-problem/problem/roman-number-to-integer3201

class Solution {
  public:
    int romanToDecimal(string &s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, 
            {'D', 500}, {'M', 1000}
        };
        
        int ans = 0;
        
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            if(i + 1 < n and roman[s[i]] < roman[s[i+1]]) {
                ans -= roman[s[i]];
            }else {
                ans += roman[s[i]];
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib