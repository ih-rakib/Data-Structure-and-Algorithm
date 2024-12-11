// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-bonus-problems/problem/minimum-sum4058

class Solution {
  public:
    string minSum(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        string x = "", y = "";
        for(int i = 0; i < n; ++i) {
            if(i % 2 == 0) x += (arr[i] + '0');
            else y += (arr[i] + '0');
        }

        int j = x.length() - 1, k = y.length() - 1, carry = 0;
        string res = "";

        while(j >= 0 or k >= 0 or carry) {
            int sum = carry;
            if(j >= 0) sum += (x[j] - '0');
            if(k >= 0) sum += (y[k] - '0');

            res += to_string(sum % 10);
            carry = sum / 10;
            j--; k--;
        }

        while(!res.empty() and res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

// Author: Ikramul Hasan Rakib