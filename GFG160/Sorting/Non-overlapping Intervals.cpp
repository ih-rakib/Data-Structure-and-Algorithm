// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/non-overlapping-intervals

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        int n = intervals.size();
        if(n == 0) return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        // [1, 5], [2, 7] -> 2 < 5: last ends = 5, cur start = 2
        int lastEnd = intervals[0][1];
        int ans = 0;

        for(int i = 1; i < n; ++i){
            if(intervals[i][0] < lastEnd) {
                ans++;
            }else {
                lastEnd = intervals[i][1];
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib