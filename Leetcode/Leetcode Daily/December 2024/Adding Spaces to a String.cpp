// https://leetcode.com/problems/adding-spaces-to-a-string/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int x = 0;
        string ans;
        for(int i = 0; i < s.length(); ++i) {
            if(x < spaces.size() and i == spaces[x]) {
                ans += ' ';
                x++;
            }
            ans += s[i]; 
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib