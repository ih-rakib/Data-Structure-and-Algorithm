// https://leetcode.com/problems/count-the-number-of-fair-pairs/

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long ans = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; ++i) {
            int left = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]) - nums.begin();
            int right = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]) - nums.begin() - 1;

            if(left <= right) {
                ans += right - left + 1;
            }
        }

        return ans;
    }
};

// Author : Ikramul Hasan Rakib

/*

    nums[i] + nums[j] >= lower --> nums[j] >= lower - nums[i]
    nums[i] + nums[j] <= upper --> nums[j] <= upper - nums[i]

*/

/*

    bruteforce:

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long ans = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                long long x = nums[i] + nums[j];
                if(lower <= x and x <= upper) ans++;
            }
        }
        return ans;
    }

*/