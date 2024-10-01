// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int> > ans;

    void bf(vector<int>& candidates, int target, vector<int>& cur, int idx){
        if(target == 0) {
            ans.push_back(cur);
            return;
        }

        if(idx == candidates.size()) return;

        if(target < 0) return; 

        cur.push_back(candidates[idx]);
        bf(candidates, target-candidates[idx], cur, idx);
        cur.pop_back();
        bf(candidates, target, cur, idx+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();

        vector<int> cur;

        bf(candidates, target, cur, 0);
        return ans;
    }
};