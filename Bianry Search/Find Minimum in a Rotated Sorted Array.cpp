//  Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        int l = 0, r = n - 1; 
        while(l <= r) {
            int mid = l + (r - l) / 2; 
            
            if(nums[l] <= nums[r]){
                ans = min(ans, nums[l]); break;
            }

            if(nums[l] <= nums[mid]){
                ans = min(ans, nums[l]);
                l = mid + 1;
            }else {
                ans = min(ans, nums[mid]);
                r = mid - 1;
            }
        }
        return ans;
    }
};

/*

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        for(int i = 0; i < n; ++i) ans = min(ans, nums[i]);
        return ans;
    }
};

*/

// Author: Ikramul Hasan Rakib