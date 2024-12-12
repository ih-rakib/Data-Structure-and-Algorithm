// https://leetcode.com/problems/take-gifts-from-the-richest-pile/

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        multiset<int> s(gifts.begin(), gifts.end());

        while(k--) {
            auto it = prev(s.end());
            long long mx = *it;
            s.erase(it);
            long long updatedElement = sqrtl(mx);
            s.insert(updatedElement);
        }

        long long sum = 0;
        for(auto x : s) sum += x;
        return sum;
    }
};

// Author: Ikramul Hasan Rakib