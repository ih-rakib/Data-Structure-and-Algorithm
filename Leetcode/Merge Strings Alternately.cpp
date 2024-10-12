// https://leetcode.com/problems/merge-strings-alternately/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length(), m = word2.length();

        int minLength = min(n, m);
        string res;

        for(int i = 0; i < minLength; ++i) {
            res += word1[i]; 
            res += word2[i];
        }

        res += word1.substr(minLength);
        res += word2.substr(minLength);

        return res;
    }
};