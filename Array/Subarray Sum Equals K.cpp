// Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, sum = 0;
        map<int,int> m;
        m[0] = 1;
        
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            
            int need = sum - k;
            
            if(m.count(sum - k)){
                ans += m[sum-k];
            }
            
            m[sum]++;
        }
        return ans;
    }
};


// Author: Ikramul Hasan Rakib