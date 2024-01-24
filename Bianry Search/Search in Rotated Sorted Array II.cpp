// Search in Rotated Sorted Array II
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            if(nums[mid] == target) return true;

            if(nums[l] == nums[mid] and nums[mid] == nums[r]){
                l++; r--; continue;
            }

            // check if left part of array is sorted
            if(nums[l] <= nums[mid]){
                if(nums[l] <= target and target <= nums[mid]){
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
            }else {
                if(nums[mid] <= target and target <= nums[r]){
                    l = mid + 1;
                }else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};

// Author: Ikramul Hasan Rakib