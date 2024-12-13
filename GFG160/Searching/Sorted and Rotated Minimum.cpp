// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/minimum-element-in-a-sorted-and-rotated-array3611c

class Solution {
  public:
    int findMin(vector<int>& arr) {
        int ans = INT_MAX;

        for(int x : arr) ans = min(ans, x);
        return ans;
    }
};

// Author: Ikramul Hasan Rakib