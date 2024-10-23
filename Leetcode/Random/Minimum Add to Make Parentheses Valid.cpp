// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int open_needed = 0, close_needed = 0;
        
        for(char c : s) {
            if(c == '('){
                close_needed++; // # of closing parenthesis we need to match opening parenthesis (close neeede actually counting '(' )
            }else if(c == ')') {
                if(close_needed > 0) {
                    close_needed--;
                }else {
                    open_needed++;
                }
            }
        }
        return open_needed + close_needed;
    }
};