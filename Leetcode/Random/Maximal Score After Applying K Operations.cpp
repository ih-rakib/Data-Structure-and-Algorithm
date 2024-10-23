// https://leetcode.com/problems/maximal-score-after-applying-k-operations/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();

        multiset<long long> s;
        for(auto &num : nums) {
            s.insert(num);
        }

        long long ans = 0;
        while(k--) {
            long long x = *s.rbegin();
            ans += x;
            s.erase(--s.end());
            x = (x + 2) / 3;
            s.insert(x);
        }
        return ans;
    }
};