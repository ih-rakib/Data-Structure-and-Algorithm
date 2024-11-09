// https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> xorCount;
        xorCount[0] = 1;

        int prefixXor = 0;
        long long ans = 0;
        for(int num : nums) {
            prefixXor ^= num;

            if(xorCount.find(prefixXor) != xorCount.end()) {
                ans += xorCount[prefixXor];
            }

            xorCount[prefixXor]++;
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib