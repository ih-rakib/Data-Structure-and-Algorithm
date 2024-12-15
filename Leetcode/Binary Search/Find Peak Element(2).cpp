// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = n - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            // checking if mid is the peak
            bool isPeak = (mid == 0 or nums[mid] > nums[mid-1]) and (mid == n-1 or nums[mid] > nums[mid+1]);

            if(isPeak) return mid;

            if(mid > 0 and nums[mid] < nums[mid-1]){ 
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return -1;
    }
};