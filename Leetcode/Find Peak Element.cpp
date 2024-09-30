// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = n - 1;

        while(l < r) {
            int mid = l + (r - l)/2;

            if(nums[mid] < nums[mid+1]){ // peak is either mid+1 or right of it
                l = mid + 1;
            }else { // peak is mid or left
                r = mid;
            }
        }
        return l; // when l = r we have found peak
    }
};