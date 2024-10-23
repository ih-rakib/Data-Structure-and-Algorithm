// https://leetcode.com/problems/count-number-of-bad-pairs/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long totalPairs = (long long)n * (n - 1) / 2;

        unordered_map<int, long long> countMap;
        long long goodPairs = 0;

        for(int i = 0; i < n; ++i) {
            int key = i - nums[i];

            if(countMap.find(key) != countMap.end()) {
                goodPairs += countMap[key];
            }

            countMap[key]++;
        }
        return totalPairs - goodPairs;
    }
};