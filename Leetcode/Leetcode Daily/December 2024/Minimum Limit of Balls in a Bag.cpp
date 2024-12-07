// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

class Solution {
public:
    bool ok(vector<int>& nums, int target, int maxOperations) {
        int op = 0;
        for(int x : nums) {
            op += (x - 1) / target; 
        }
        return op <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int ans = r;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(ok(nums, mid, maxOperations)) {
                ans = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib