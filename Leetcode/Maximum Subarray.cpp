// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9, cur = -1e9;

        for(int i = 0; i < nums.size(); ++i){
          cur = max(cur + nums[i], nums[i]); // either extend the previous one(cur + nums[i]) or start new one (nums[i])
          ans = max(cur, ans);
        }
        return ans;
    }
};


// this gives time limit exceed: O(n^2)

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int ans = INT_MIN;

//         for(int i = 0; i < nums.size(); ++i){
//            int cur = 0;
//            for(int j = i; j < nums.size(); ++j){
//             cur += nums[j];
//             ans = max(ans, cur);
//            }
//         }
//         return ans;
//     }
// };