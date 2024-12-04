// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/number-to-words0335

class Solution {
  public:
    vector<string> belowTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};

    string hundred(int n) {
        string res = "";

        if(n >= 100) {
            res += belowTwenty[n / 100] + " Hundred "; 
            n %= 100; 
        }

        if(n >= 20) {
            res += tens[n / 10] + " ";
            n %= 10;
        }

        if(n > 0) {
            res += belowTwenty[n] + " ";
        }
        return res;
    }

    string convertToWords(int n) {
        if(n == 0) return "Zero";

        string ans = "";
        int i = 0;

        while(n) {
            if(n % 1000 != 0) {
                ans = hundred(n % 1000) + thousands[i] + " " + ans;
            }
            n /= 1000;
            i++;
        }

        while(ans.back() == ' ') ans.pop_back();
        return ans;
    }
};

// Author: Ikramul Hasan Rakib : 