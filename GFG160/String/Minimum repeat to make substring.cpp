// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        int n = s1.length(), m = s2.length();

        string temp = s1;
        int ans = 1;

        while(temp.size() < m) {
            temp += s1;
            ans++;
        }

        if(temp.find(s2) != string::npos) return ans;
        
        temp += s1;
        ans++;
        // cout << temp << '\n';
        if(temp.find(s2) != string::npos) return ans;
        return -1;
    }
};

// Author: Ikramul Hasan Rakib