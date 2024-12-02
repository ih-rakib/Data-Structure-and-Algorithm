// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length(), m = searchWord.length();

        stringstream ss(sentence);
        string word;
        int index = 1;

        while(ss >> word) {
            if(word.length() >= m and word.substr(0, m) == searchWord) return index;
            index++;
        }
        return -1;
    }
};

// Author: Ikramul Hasan Rakib