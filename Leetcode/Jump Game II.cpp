// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int maxReachable = 0;
        int currentPos = 0;
        int jumps = 0;

        for(int i = 0; i < n - 1; ++i) { // n - 1 cause we can't make jump from last indes; so it won't count
            if(i > maxReachable) {
                return -1;
            }

            maxReachable = max(maxReachable, i + nums[i]);

            if(i == currentPos) {
                jumps++;
                currentPos = maxReachable;
            }
        }
        return jumps;
    }
};