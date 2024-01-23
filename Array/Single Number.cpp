// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), single = 0;
        for(auto &x : nums) single ^= x;
        return single;
    }
};

// Author: Ikramul Hasan Rakib