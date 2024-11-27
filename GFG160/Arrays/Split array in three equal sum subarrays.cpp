// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/split-array-in-three-equal-sum-subarrays

class Solution {
  public:
    vector<int> findSplit(vector<int>& arr) {
        int n = arr.size();

        int total = accumulate(arr.begin(), arr.end(), 0);

        if(total % 3 != 0) return {-1, -1};

        int target = total / 3;

        int s = -1, e = -1, cur = 0;

        for(int i = 0; i < n; ++i) {
            cur += arr[i];

            if(s == -1 && cur == target) {
                s = i;
            }else if(s != -1 && cur == 2 * target) {
                e = i;
                break;
            }
        }

        if(e != -1 && e < n - 1) return {s, e};
        return {-1, -1};
    }
};

// Author: Ikramul Hasan Rakib