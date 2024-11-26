// https://leetcode.com/problems/defuse-the-bomb/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> ans(n, 0);

        if(k == 0) return ans;

        if(k > 0) {
            for(int i = 0; i < n; ++i) {
                int sum = 0;
                for(int j = 1; j <= k; ++j) {
                    sum += code[(i + j) % n];
                }
                ans[i] = sum;
            }
        }else {
            for(int i = 0; i < n; ++i) {
                int sum = 0;
                for(int j = 1; j <= abs(k); ++j) {
                    sum += code[(i - j + n) % n];
                }
                ans[i] = sum;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib

/*

    next k number: (i + j) % n (for i = 1 to k)
    prev k number: (i - j + n) % n (for i = 1 to k)

*/