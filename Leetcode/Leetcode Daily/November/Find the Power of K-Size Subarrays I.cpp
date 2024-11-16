// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/

class Solution {
public:
    bool ok(vector<int>& nums,int start, int k){
        int n = nums.size();

        for(int i = start; i < start + k - 1; ++i) {
            if(nums[i+1] - nums[i] != 1) return false;
        }
        return true;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n - k + 1; ++i) {
            if(ok(nums, i, k)) {
                ans.push_back(nums[i+k-1]);
            }else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib

/*

bruteforce:

class Solution {
    public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n - k + 1; ++i) {
            bool isValid = true;
            
            for (int j = i; j < i + k - 1; ++j) {
                if (nums[j + 1] - nums[j] != 1) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                ans.push_back(*max_element(nums.begin() + i, nums.begin() + i + k));
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};


*/