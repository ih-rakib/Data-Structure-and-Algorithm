// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

        for(int i = 0; i < n; ++i) {
            pq.push({nums[i], i}); // {val, idx}
        }

        long long ans = 0;

        while(!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();

            if(vis[idx]) continue;

            ans += val;

            if(idx > 0) vis[idx-1] = true;
            if(idx < n - 1) vis[idx + 1] = true;
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib