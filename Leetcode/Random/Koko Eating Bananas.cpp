// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    bool ok(vector<int>& piles, int h, int k) { // if Koko can finish in h hours with eating speed k
        long long hour = 0;
        for(int curPile : piles) {
            hour += (curPile + k - 1) / k; // time needed to eat curPile (k ta khete 1hr, curPile ta khete curPile/k hr(ceil) )
        }
        return hour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            if(ok(piles, h, mid)){
                ans = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }

        return ans;
    }
};