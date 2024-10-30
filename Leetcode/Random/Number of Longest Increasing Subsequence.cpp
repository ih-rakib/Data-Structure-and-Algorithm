// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> lis(n,1), count(n,1);

        int maxLength = 1;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    if(lis[j] + 1 > lis[i]) { // found a new increasing sequence
                        lis[i] = lis[j] + 1;
                        count[i] = count[j];
                    }else if(lis[i] == lis[j] + 1) {
                        count[i] += count[j];
                    }
                }
            }
            maxLength = max(maxLength, lis[i]);
        }

        int total = 0;
        for(int i = 0; i < n; ++i) {
            if(lis[i] == maxLength) {
                total += count[i];
            }
        }
        return total;
    }
};

// Author: Ikramul Hasan Rakib