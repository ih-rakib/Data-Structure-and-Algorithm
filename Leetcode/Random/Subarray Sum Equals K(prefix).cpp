// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, curSum = 0;;

        unordered_map<int, int> prefSumCount;

        prefSumCount[0] = 1;

        for(int i = 0; i < n; ++i) {
            curSum += nums[i];

            int target = curSum - k;

            if(prefSumCount.find(target) != prefSumCount.end()) {
                ans += prefSumCount[target];
            }

            prefSumCount[curSum]++;
        }
        return ans;
    }
};

// pref[r] - pref[l-1] = k
// pref[l-1] = pref[r] - k --> now find how many pref[l-1] there