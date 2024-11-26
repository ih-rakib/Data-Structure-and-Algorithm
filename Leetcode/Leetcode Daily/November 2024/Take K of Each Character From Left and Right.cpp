// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();

        vector<int> count(3, 0);

        for(char c : s) count[c-'a']++;

        int minCount = *min_element(count.begin(), count.end());

        if(minCount < k) return -1;

        int window = 0; // largest substring where each character ('a', 'b', 'c') appears at least k times
        int l = 0;

        for(int r = 0; r < n; ++r) {
            count[s[r]-'a']--;

            while(*min_element(count.begin(), count.end()) < k) {
                count[s[l] - 'a']++;
                l++;
            }
            window = max(window, r - l + 1);
        }
        return n - window;
    }
};

// Author: Ikramul Hasan Rakib

/*

    class Solution {
    public:
    int takeCharacters(string s, int k) {
        int n = s.length();

        int A = 0, B = 0, C = 0;

        for(char c : s) {
            A += (c == 'a');
            B += (c == 'b');
            C += (c == 'c');
        }

        if(A < k || B < k || C < k) {
            return -1;
        }

        int targetA = A - k; // I can remove A - k occurences of 'a'
        int targetB = B - k;
        int targetC = C - k;

        int curA = 0, curB = 0, curC = 0;
        int window = 0, l = 0;
        for(int r = 0; r < n; ++r) {
            // add current char to window
            if(s[r] == 'a') curA++;
            if(s[r] == 'b') curB++;
            if(s[r] == 'c') curC++;

            while(curA > targetA or curB > targetB or curC > targetC) { // if excess amount of any char present in window (invalid - k er cheye kome jabe)
                // shrink window from left
                if(s[l] == 'a') curA--;
                if(s[l] == 'b') curB--;
                if(s[l] == 'c') curC--;
                l++;
            }
            window = max(window, r - l + 1);
        }
        return n - window;
    }
};

    window: largest valid substring that can be kept (at least k occurences of each)
    n - window: rest i can remove that's why

*/