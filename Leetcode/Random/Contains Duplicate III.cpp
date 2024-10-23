// https://leetcode.com/problems/contains-duplicate-iii/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        if (indexDiff <= 0 || valueDiff < 0) return false;

        int left = 0, right = 0, res = INT_MAX;

        map<int, int> mp;

        while(right < n) {
            if(right - left > indexDiff) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }

            auto it = mp.upper_bound(nums[right]);

            if(it != mp.end()) {
                res = min(res, abs(it -> first - nums[right]));
            }

            if(it != mp.begin()) {
                res = min(res, abs(prev(it) -> first - nums[right]));
            }

            mp[nums[right]]++;
            right++;
        }

        return res <= valueDiff;
    }
};
