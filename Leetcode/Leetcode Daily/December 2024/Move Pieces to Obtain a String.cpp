// https://leetcode.com/problems/move-pieces-to-obtain-a-string/

class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        int n = start.length();

        while(i <= n and j <= n) {
            while(i < n and start[i] == '_') i++;
            while(j < n and target[j] == '_') j++;

            if(i == n or j == n) {
                return i == n and j == n;
            }

            if(start[i] != target[j]) return false;
            if(start[i] == 'L' and i < j) return false;
            if(start[i] == 'R' and i > j) return false;
            
            i++;
            j++;
        }
        return true;
    }
};

// Author: Ikramul Hasan Rakib