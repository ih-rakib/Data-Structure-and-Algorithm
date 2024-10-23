// https://leetcode.com/problems/count-array-pairs-divisible-by-k/

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int, int> gcdCount; // store frequency of gcd(nums[i], k)
        long long pairs = 0;

        for(int num : nums) {
            long long gcd_i = __gcd(num, k);

            for(auto &[gcd_j, freq] : gcdCount) {
                if((long long) (gcd_i * gcd_j) % k == 0) {
                    pairs += freq;
                }
            }

            gcdCount[gcd_i]++;
        }
        return pairs;
    }
};

// if gcd(i, k) * gcd(j, k) is divisible by k then i * j is also divisible by k