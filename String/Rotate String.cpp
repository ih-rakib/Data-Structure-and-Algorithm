// Rotate String
// https://leetcode.com/problems/rotate-string/

class Solution {
public:
    bool rotateString(string s, string goal) {
        s += s;
        return s.length() == goal.length()*2 and s.find(goal) != string::npos;
    }
};

// Author: Ikramul Hasan Rakib