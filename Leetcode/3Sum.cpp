// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int> > triplets;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i) {
            int j = i + 1, k = n -1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                }else if(sum < 0) {
                    j++;
                }else {
                    k--;
                }
            }
        }

        sort(triplets.begin(), triplets.end());
        triplets.erase(unique(triplets.begin(), triplets.end()), triplets.end());
        return triplets;
    }
};