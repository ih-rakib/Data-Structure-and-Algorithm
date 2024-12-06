// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s(banned.begin(), banned.end());

        int cur = 0, ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(!s.count(i)) {
                if(cur + i <= maxSum) {
                    ans++;
                    cur += i;
                }
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib