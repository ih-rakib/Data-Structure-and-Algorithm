// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/number-of-occurrence2259

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        auto lower = lower_bound(arr.begin(), arr.end(), target);
        auto upper = upper_bound(arr.begin(), arr.end(), target);

        return upper - lower;
    }
};

// Author: Ikramul Hasan Rakib