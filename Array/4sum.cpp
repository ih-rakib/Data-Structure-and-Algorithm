// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i) {
            if(i > 0 and nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n; ++j) {
                if(j > i+1 and nums[j] == nums[j-1]) continue;
                int k = j + 1, l = n - 1;
                while(k < l) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++; l--;
                        while(k < l and nums[k] == nums[k-1]) k++;
                        while(k < l and nums[l] == nums[l+1]) l--; 
                    }else if(sum < target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};

/*


// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                int k = j + 1, l = n - 1;
                while(k < l) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++; l--;
                    }else if(sum < target) k++;
                    else l--;
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

*/