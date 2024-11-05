// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome1(string s) {
        string cleaned = "";
        for(char c : s) if(isalnum(c)) cleaned += tolower(c);
        return cleaned == string(cleaned.rbegin(), cleaned.rend());
    }

    // better approach(SC: O(1))
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while(l < r) {
            if(!isalnum(s[l])) {
                l++; continue;
            }

            if(!isalnum(s[r])) {
                r--; continue;
            }

            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++; r--;
        }
        return true;
    }
};

/*

    isPalindrome1
    TC: O(n)
    SC: O(n)


    isPalindrome1
    TC: O(n)
    SC: O(1)

*/

// Author: Ikramul Hasan Rakib