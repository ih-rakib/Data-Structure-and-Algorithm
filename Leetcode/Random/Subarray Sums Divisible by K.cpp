// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> prefMod;
        prefMod[0] = 1;
        int currentSum = 0, ans = 0;

        for(int i = 1; i <= n; ++i) {
            currentSum += nums[i-1];
            int currentMod = ((currentSum % k) + k) % k;

            if(prefMod.find(currentMod) != prefMod.end()) {
                ans += prefMod[currentMod];
            }

            prefMod[currentMod]++;
        }
        return ans;
    }
};


// sum(i, j) = prefixSum(j) - prefixSum(i-1)
// (prefixSum(j) - prefixSum(i-1)) % k == 0
// prefixSum(j) % k == prefixSum(i-1) % k
