// https://leetcode.com/problems/find-right-interval/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> results(n, -1);
        vector<pair<int, int> > starts;

        for(int i = 0; i < n; ++i) {
            starts.push_back({intervals[i][0], i}); // (start, index)
        }

        sort(starts.begin(), starts.end()); // sort according to start interval

        // for each interval perform binary search to find right interval of it
        for(int i = 0; i < n; ++i) {
            int end = intervals[i][1];

            int l = 0, r = n - 1, bestIndex = -1;

            while(l <= r) {
                int mid = l + (r - l) / 2;

                if(starts[mid].first >= end) {
                    bestIndex = starts[mid].second;
                    r = mid - 1; // search for smaller valid index
                }else {
                    l = mid + 1;
                }
            }
            results[i] = bestIndex;
        }

        return results;
    }
};