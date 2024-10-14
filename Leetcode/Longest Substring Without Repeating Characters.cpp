// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> freq;

        int l = 0, r = 0, maxLen = 0;

        while(r < n) {
            freq[s[r]]++;
            int k = r - l + 1; // window size

            if(freq.size() == k) {
                maxLen = max(maxLen, k);
            }

            if(freq.size() < k) {
                while(freq.size() < k) {
                    freq[s[l]]--;
                    if(freq[s[l]] == 0) {
                        freq.erase(s[l]);
                    }
                    l++;
                    k = r - l + 1;
                }
            }
            r++;
        }
        return maxLen;
    }
};
