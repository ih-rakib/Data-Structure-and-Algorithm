// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(k < 0) return 0;

        unordered_map<int, int> numCount;

        int ans = 0;

        for(int num : nums) {
           if(numCount.find(num - k) != numCount.end()) ans += numCount[num - k];
           if(numCount.find(num + k) != numCount.end()) ans += numCount[num + k];

           numCount[num]++;
        }
        return ans;
    }
};