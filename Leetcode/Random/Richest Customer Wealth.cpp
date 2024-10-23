// https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[0].size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int cur = 0;
            for(int j = 0; j < m; ++j){
                cout << accounts[i][j] << " ";
                cur += accounts[i][j];
            }
            ans = max(ans, cur);
            cout << '\n';
        }
        return ans;
    }
};