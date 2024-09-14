// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > quadruplets;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int k = j + 1, l = n - 1;
                while(k < l) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++; l--;
                    }else if (sum < target) {
                        k++;
                    }else {
                        l--;
                    }
                }
            }
        }
        sort(quadruplets.begin(), quadruplets.end());
        quadruplets.erase(unique(quadruplets.begin(), quadruplets.end()), quadruplets.end());
        return quadruplets;
    }
};