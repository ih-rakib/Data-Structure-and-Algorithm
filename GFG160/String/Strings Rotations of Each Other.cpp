// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/check-if-strings-are-rotations-of-each-other-or-not-1587115620

class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        if(s1.length() != s2.length()) return false;
        s1 += s1;
        return s1.find(s2) != string::npos;
    }
};

// Author: Ikramul Hasan Rakib