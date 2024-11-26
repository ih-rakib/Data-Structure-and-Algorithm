// https://leetcode.com/problems/find-if-array-can-be-sorted/

class Solution {
public:
    int countSetBits(int num) { // __builtin_popcount
        int cnt = 0;
        while(num){
            cnt += (num & 1);
            num >>= 1;
        }
        return cnt;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int prevMax = -1;
        int curMax = nums[0];

        for(int i = 1; i < n; ++i) {
            int curBitCount = __builtin_popcount(nums[i]);
            int prevBitCount = __builtin_popcount(nums[i-1]);

            if(prevBitCount != curBitCount) {
                prevMax = curMax;
                curMax = nums[i];
            }else {
                curMax = max(curMax, nums[i]);
            }

            if(nums[i] < prevMax) return false;
        }
        return true;
    }
};

// Author: Ikramul Hasan Rakib