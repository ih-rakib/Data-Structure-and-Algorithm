// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int window_or = 0;
        int minLen = n + 1;
        int left = 0;
        vector<int> bit_count(32, 0);

        for(int right = 0; right < n; ++right) {
            window_or |= nums[right];

            // calculate how many element has i'th bit set from left to right
            for(int i = 0; i < 32; ++i) {
                if(nums[right] & (1 << i)) {
                    bit_count[i]++;
                }
            }

            while(left <= right && window_or >= k) {
                minLen = min(minLen, right - left + 1);

                // we need to shrink window by removing left - so removing the effect of nums[left]
                for(int i = 0; i < 32; ++i) {
                    if(nums[left] & (1 << i)) { // nums[left] also have i'th bit set
                        bit_count[i]--;

                        if(bit_count[i] == 0) { // no element in the window have i'th bit set 
                            window_or ^= (1 << i); // removing the contribution of i'th bit by unsetting it from window_or
                        }
                    }
                }

                left++;
            }
        }
        return minLen == n + 1 ? -1 : minLen;
    }
};

// Author: Ikramul Hasan Rakib

/*

    bruteforce:

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n + 1;
        for(int i = 0; i < n; ++i) {
            int curOr = 0;
            for(int j = i; j < n; ++j) {
                curOr |= nums[j];
                if(curOr >= k) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return (ans == n+1) ? -1 : ans;
    }


*/