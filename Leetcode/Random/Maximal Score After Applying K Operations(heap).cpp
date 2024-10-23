// https://leetcode.com/problems/maximal-score-after-applying-k-operations/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<long long> p;
        for(auto &num : nums) {
            p.push(num);
        }

        long long ans = 0;
        while(k--) {
            long long x = p.top();
            p.pop();
            ans += x;
            x = (x + 2) / 3;
            p.push(x);
        }
        return ans;
    }
};