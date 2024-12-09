// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/insert-interval-1666733333

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        vector<vector<int> > ans;

        for(auto &interval : intervals) {
            if(newInterval[1] < interval[0]) {
                ans.push_back(newInterval);
                newInterval = interval;
            }else if(newInterval[0] > interval[1]) {
                ans.push_back(interval);
            }else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }

        ans.push_back(newInterval);
        return ans;
    }
};

// Author: Ikramul Hasan Rakib