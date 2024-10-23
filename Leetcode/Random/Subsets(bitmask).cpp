// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        int n = nums.size();
        int total = (1 << n);

        for(int mask = 0; mask < total; ++mask) {
            vector<int> subset;
            for(int j = 0; j < n; ++j) {
                if(mask & (1 << j)) { // setbit - so include it
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};