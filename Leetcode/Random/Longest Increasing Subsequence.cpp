// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> lis(n, 1);

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]){
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }
        return *max_element(lis.begin(), lis.end());
    }
};

// lis[i] = longest increasing subsequence ending at i

// Author: Ikramul Hasan Rakib