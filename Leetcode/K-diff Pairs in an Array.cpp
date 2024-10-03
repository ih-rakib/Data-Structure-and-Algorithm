// https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();

        if(k < 0) return 0;

        unordered_map<int, int> numCount;

        for(int num : nums) numCount[num]++;
        int ans = 0;

        for(auto& [num, freq] : numCount) {
            if(k == 0) {
                if(freq > 1) {
                    ans++;
                }
            }else {
                if(numCount.find(num - k) != numCount.end()){
                    ans++;
                }
            }
        }
        return ans;
    }
};