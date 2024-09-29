// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int limit = n/3;

        unordered_map<int, int> freq;

        for(auto &val : nums) {
            freq[val]++;
        }

        vector<int> ans;
        for(auto &x : freq){
            if(x.second > limit){
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};