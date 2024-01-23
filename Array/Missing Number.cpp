// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),sum = 0; 
        for(auto &x : nums) sum += x;
        int missing = n*(n+1)/2 - sum;
        return missing;
    }
};

// Author: Ikramul Hasan Rakib