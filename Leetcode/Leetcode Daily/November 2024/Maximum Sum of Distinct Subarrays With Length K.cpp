// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> distinct;
        long long curSum = 0, ans = 0;
        int l = 0;

        for(int r = 0; r < n; ++r) {
            while(r - l + 1 > k || distinct.count(nums[r])) {
                distinct.erase(nums[l]);
                curSum -= nums[l];
                l++;
            }

            distinct.insert(nums[r]);
            curSum += nums[r];

            if(r - l + 1 == k) {
                ans = max(ans, curSum);
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib

/*

    what if it was maximum length of distinct subarray with sum k

    int maxLength = 0, curSum = 0; 
    for(int r = 0; i < n; ++i) {
        while(distinct.count(nums[r]) or curSum + nums[r] > k) {
            distinct.erase(nums[l]);
            curSum -= nums[l];
            l++;
        }

        distinct.insert(nums[r]);
        curSum += nums[r];

        if(curSum == k) {
            maxLength = max(maxLength, r - l + 1);
        }
    }
    return maxLength;

*/