// https://leetcode.com/problems/rotate-string/

class Solution {
public:
    bool rotateString(string s, string goal) {
        s += s;
        return s.length() == 2 * goal.length() and s.find(goal) != string::npos;
    }
};

// Author: Ikramul Hasan Rakib