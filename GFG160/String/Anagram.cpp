// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/anagram-1587115620

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};

// Author: Ikramul Hasan Rakib