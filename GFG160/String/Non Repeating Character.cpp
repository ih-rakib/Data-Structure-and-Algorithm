// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/non-repeating-character-1587115620

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        unordered_map<char, int> seen;

        for(char c : s) seen[c]++;

        for(char c : s) {
            if(seen[c] == 1) return c;
        }
        return '$';
    }
};

// Author: Ikramul Hasan Rakib