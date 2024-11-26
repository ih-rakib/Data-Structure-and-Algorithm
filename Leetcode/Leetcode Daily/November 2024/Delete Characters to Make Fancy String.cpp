// https://leetcode.com/problems/delete-characters-to-make-fancy-string/

class Solution {
public:
    string makeFancyString(string s) {
        string res;
        
        for(char c : s) {
            int n = res.length();

            if(n >= 2 and res[n-1] == c and res[n-2] == c) continue;
            else res += c;
        }
        return res;
    }
};


// Author: Ikramul Hasan Rakib

/*


class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();

        int k = 0;

        for(int i = 0; i < n; ++i){
            if(k >= 2 and s[i] == s[k-1] and s[i] == s[k-2]) {
                continue;
            }else s[k++] = s[i];
        }
        return s.substr(0, k);
    }
};

// generalised for k consecutive character
class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        int t = 0; 

        int k = 3; // k consecutive character
        for(int i = 0; i < n; ++i) {
            int cnt = 0;

            for(int x = 0; x < k; ++x) {
                if(t-x >= 0 and s[t-x] == s[i]) {
                    cnt++;
                }else break;
            }

            if(cnt < k) {
                s[t++] = s[i];
            }
        }
        return s.substr(0, t);
    }
};

*/