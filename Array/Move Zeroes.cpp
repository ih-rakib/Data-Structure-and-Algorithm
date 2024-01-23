// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(auto &x : nums) {
            if(x != 0) temp.push_back(x);
        }
        int non = temp.size();
        for(int i = 0; i < non; ++i) nums[i] = temp[i];
        for(int i = non; i < n; ++i) nums[i] = 0;
    }
};

// Author: Ikramul Hasan Rakib