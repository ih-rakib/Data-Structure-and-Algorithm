// https://leetcode.com/problems/make-sum-divisible-by-p/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for(int num : nums) {
            total += num;
        }

        int totalMod = (total % p);
        if(totalMod == 0) return 0;
        long long currentSum = 0;
        unordered_map<int, int> pref;
        pref[0] = 0;
        int minLen = n;

        for(int i = 1; i <= n; ++i) {
            currentSum += nums[i-1];
            int currentMod = currentSum % p;

            int targetMod = (currentMod - totalMod + p) % p;

            if(pref.find(targetMod) != pref.end()) {
                int len = i - pref[targetMod];
                minLen = min(len, minLen);
            }

            pref[currentMod] = i; 
        }

        return (minLen == n) ? -1 : minLen;
    }
};