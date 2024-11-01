// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        // step 01: calculate LIS for each portion from the left
        vector<int> lis(n, 1);

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }

        // step 02: calculate LDS for each portion from the right
        vector<int> lds(n, 1);
        for(int i = n-2; i >= 0; --i) {
            for(int j = n-1; j > i; --j) {
                if(nums[i] > nums[j]) {
                    lds[i] = max(lds[i], 1 + lds[j]);
                }
            }
        }

        // step 03: calculate the maximum length of a mountain array
        int maxMountainlength = 0;

        for(int i = 1; i < n-1; ++i) {
            if(lis[i] > 1 and lds[i] > 1) { // ensure there is an increasing and decreasing sequence
                maxMountainlength = max(maxMountainlength, lis[i]+lds[i]-1); // -1 as peak element calculated twice
            }
        }
        return n - maxMountainlength;
    }
};

// Good problem!
// Author: Ikramul Hasan Rakib