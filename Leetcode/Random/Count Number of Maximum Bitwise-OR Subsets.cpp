// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;

        for(int num : nums) maxOr |= num;

        int ans = 0;

        for(int mask = 0; mask < (1 << n); ++mask) {
            int subOr = 0;
            for(int i = 0; i < n; ++i) {
                if((1 << i) & mask) {
                    subOr |= nums[i];
                }
            }
            if(subOr == maxOr) ans++;
        }
        return ans;
    }
};