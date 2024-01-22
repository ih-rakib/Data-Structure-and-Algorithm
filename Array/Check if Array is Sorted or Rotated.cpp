// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), breaking_point = 0;
        for(int i = 0; i < n; ++i) {
            breaking_point += (nums[i] > nums[(i+1)%n]);
        }
        return breaking_point <= 1;
    }
};

// Author: Ikramul Hasan Rakib