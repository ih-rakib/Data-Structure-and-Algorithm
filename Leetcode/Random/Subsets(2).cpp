// https://leetcode.com/problems/subsets/

class Solution {
public:
   vector<vector<int> > ans;

   void bf(vector<int>& nums, vector<int>& cur, int idx) {
    if(idx == nums.size()){
        ans.push_back(cur);
        return;
    }

    cur.push_back(nums[idx]);
    bf(nums, cur, idx+1);
    cur.pop_back();
    bf(nums, cur, idx+1);
   }

    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();

        vector<int> cur;

        bf(nums, cur, 0);

        return ans;
    }
};