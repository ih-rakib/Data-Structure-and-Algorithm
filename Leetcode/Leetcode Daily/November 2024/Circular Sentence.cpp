// https://leetcode.com/problems/circular-sentence/

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();

        if(sentence[n-1] != sentence[0]) return false;

        for(int i = 1; i < n; ++i) {
            if(sentence[i] == ' ') {
                if(sentence[i-1] != sentence[i+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

/*

    Time: O(n)
    Space: O(1)

*/

/*

class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        vector<string> words;
        string word;

        while(ss >> word) {
            words.push_back(word);
        }

        int n = words.size();

        for(int i = 0; i < n; ++i) {
            char last = words[i].back();
            char first = words[(i+1)%n][0];

            if(last != first) {
                return false;
            }
        }
        return true;
    }
};


    Time: O(n)
    Space: O(n) 

*/

// Author: Ikramul Hasan Rakib