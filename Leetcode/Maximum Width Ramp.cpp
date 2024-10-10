// https://leetcode.com/problems/maximum-width-ramp/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int> > v;
        int ans = 0;
        
        for(int i = 0; i < n; ++i) v.push_back({nums[i], i});
        sort(v.begin(), v.end());

        int minIndex = INT_MAX;

        for(auto[val, idx] : v) {
            minIndex = min(minIndex, idx);
            ans = max(ans, idx - minIndex);
        }

        return ans;
    }
};