// https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> numIndices;

        for(int i = 0; i < n; ++i) {
            if(numIndices.find(nums[i]) != numIndices.end()) {
                if(abs(i - numIndices[nums[i]] <= k)) {
                    return true;
                }
            }

            numIndices[nums[i]] = i; 
        }
        return false;
    }
};