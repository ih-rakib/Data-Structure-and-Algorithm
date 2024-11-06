// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0;
        int maxLen = 1;

        if(s.empty()) return "";

        auto expandAroundCenter = [&](int left, int right) {
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--; right++;
            }
            // at this position, left is one pos left to actual palindrom and right is one pos right
            // so len = (right - 1) - (left + 1) + 1 = right - left - 1
            return right - left - 1;
        }

        for(int i = 0; i < n; ++i) {
            int oddLen = expandAroundCenter(i, i);
            int evenLen = expandAroundCenter(i, i+1);
            int len = max(oddLen, evenLen);

            if(len > maxLen) {
                maxLen = len;
                start = i - (len-1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};

// Author: Ikramul Hasan Rakib

/*

    for each character, consider it as center of palindromic string and expand aroud
    - Odd length palindrome (single center)
    - Even length palindrome (center between i and i+1) | two char as center

*/