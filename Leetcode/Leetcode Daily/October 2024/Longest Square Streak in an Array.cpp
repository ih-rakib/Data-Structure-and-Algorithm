// Longest Square Streak in an Array

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        unordered_set<long long> num_set(nums.begin(), nums.end());
        int ans = 0;
        
        for(int num : nums) {
            int len = 1;
            long long cur = num;

            while(num_set.count(cur * cur)) {
                len++;
                cur *= cur;
            }

            if(len >= 2) ans = max(ans, len);
        }

        return (ans >= 2 ? ans : -1);
    }
};