// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0, ans = 0;

        for(int right = 0; right < n; ++right) {
            while(nums[right] - nums[left] > 2*k) left++;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib