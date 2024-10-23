// https://leetcode.com/problems/subsets/

class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int> &current, vector<vector<int> > &result){
        // push current subset
        result.push_back(current);

        for(int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(nums, i+1, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result; // to store all subsets
        vector<int> current; // store current subset

        // backtracking: starting from index 0
        backtrack(nums, 0, current, result);

        return result;
    }
};