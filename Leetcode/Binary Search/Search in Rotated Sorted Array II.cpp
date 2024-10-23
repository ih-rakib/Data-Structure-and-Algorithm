// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int left = 0, right = n - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                return true;
            }

            // skip duplicates to get the distinct rotated sorted array (to get sorted half)
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++; right--;
            }else if(nums[left] <= nums[mid]){ // left half is sorted
                if(nums[left] <= target && target <= nums[mid]){
                    right = mid - 1; // target in left half
                }else {
                    left = mid + 1; // target in right half
                }
            }else { // right half is sorted
                if(nums[mid] <= target && target <= nums[right]){
                    left = mid + 1; // target in right half
                }else {
                    right = mid - 1; // target in left half
                }
            }
        }
        return false; // target not found
    }
};