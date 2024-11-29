// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/add-binary-strings3805

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        int i = s1.length() - 1, j = s2.length() - 1;

        string res = "";
        int carry = 0;

        while(i >= 0 or j >= 0 or carry) {
            int a = (i >= 0 and s1[i] == '1' ? 1 : 0); i--;
            int b = (j >= 0 and s2[j] == '1' ? 1 : 0); j--;

            int sum = a + b + carry;
            res += (sum % 2) + '0'; // 1 + 1 = 1, carry = 1
            carry = sum / 2;
        }
        
        reverse(res.begin(), res.end());
        int n = res.length();
        int s = 0;

        while(s < n and res[s] == '0') s++;

        if(s == n) return "0";
        return res.substr(s);
    }
};

// Author: Ikramul Hasan Rakib