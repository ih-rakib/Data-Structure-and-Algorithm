// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/

class Solution {
public:
    // vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    //     int n = nums.size();

    //     for(int i = 0; i < k; ++i) {
    //         auto x = min_element(nums.begin(), nums.end());
    //         *x *= multiplier;
    //     }
    //     return nums;
    // }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for(int i = 0; i < n; ++i) pq.push({nums[i], i});

        while(k--) {
            auto [val, idx] = pq.top(); pq.pop();
            nums[idx] = val * multiplier;
            pq.push({nums[idx], idx});
        }
        return nums;
    }
};

// Author: Ikramul Hasan Rakib