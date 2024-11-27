// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/maximize-number-of-1s0905

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();

        int r = 0, l = 0, zero = 0, ans = 0;

        while(r < n) {
            if(arr[r] == 0) {
                zero++;
            }

            // shrink the window
            while(zero > k) {
                if(arr[l] == 0) zero--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib

/*

    sliding window

    if current window have at most k occurences of 0, we can flip them and this is a valid window
    from all valid window, take the maximum one

*/