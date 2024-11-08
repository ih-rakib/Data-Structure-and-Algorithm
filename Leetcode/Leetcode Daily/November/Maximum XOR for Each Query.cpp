// https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxK = (1 << maximumBit) - 1;
        vector<int> ans(n);
        int curXor = 0;

        for(int num : nums) curXor ^= num;

        for(int i = 0; i < n; ++i) {
            ans[i] = curXor ^ maxK;
            curXor ^= nums[n-1-i]; // to eliminate last number
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib

/*

    curXor ^ some k = maximum (max possible is maxK - as it has all bit set)
    some k = curXor ^ maximum (maxK)

*/