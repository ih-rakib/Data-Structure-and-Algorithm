// https://leetcode.com/problems/string-compression-iii/

class Solution {
public:
    string compressedString(string word) {
        int n = word.length();

        int k = 0;
        string ans;
        
        while(k < n) {
            char c = word[k];
            int curCharCount = 0;
            while(k < n and word[k] == c and curCharCount < 9) {
                curCharCount++; k++;
            }
            ans += to_string(curCharCount);
            ans += c;
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib