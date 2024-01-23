// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), one = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == 1) {
                one++;
            }else one = 0;
            ans = max(ans, one);
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib