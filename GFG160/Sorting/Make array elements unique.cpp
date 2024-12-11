// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-bonus-problems/problem/make-array-elements-unique--170645

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return 0;

        sort(arr.begin(), arr.end());

        int ans = 0;

        for(int i = 1; i < n; ++i) {
            if(arr[i] <= arr[i - 1]) {
                ans += (arr[i-1] - arr[i] + 1);
                arr[i] = arr[i-1] + 1;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib