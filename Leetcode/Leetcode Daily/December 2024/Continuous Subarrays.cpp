// https://leetcode.com/problems/continuous-subarrays/

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int l = 0;
        multiset<int> window;

        for(int r = 0; r < n; ++r) {
            window.insert(nums[r]);

            while(*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[l]));
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }

};

// Author: Ikramul Hasan Rakib

/*

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int l = 0;
        
        int curMin = nums[0], curMax = nums[0];
        
        for (int r = 0; r < n; ++r) {
            // Update the current max and min for the window from l to r
            curMin = *min_element(nums.begin() + l, nums.begin() + r + 1);
            curMax = *max_element(nums.begin() + l, nums.begin() + r + 1);
            
            // While the difference between max and min exceeds 2, move the left pointer
            while (curMax - curMin > 2) {
                l++;
                curMin = *min_element(nums.begin() + l, nums.begin() + r + 1);
                curMax = *max_element(nums.begin() + l, nums.begin() + r + 1);
            }
            
            // Add the number of valid subarrays ending at r
            count += r - l + 1;
        }
        
        return count;
    }

    - for each subarray ending at r, find min and max from l to r
    - if diff between them exceeds 2, move left pointer and update min, max
    - finally when a vaid subarray is found, add r - l + 1 to ans

    -> why r - l + 1? [1, 2, 3] => [1,2,3], [2,3], [3] is valid -(ending at 3)
};

*/