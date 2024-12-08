// https://leetcode.com/problems/two-best-non-overlapping-events/

class Solution {
public:
    int f(vector<vector<int>>& events, int cur) {
        int l = 0, r = cur - 1;
        int idx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][1] < events[cur][0]) {
                idx = mid; // latest non-overlapping event index
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return idx;
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1]; // sort events by end time
        });

        int n = events.size();
        vector<int> maxVal(n, 0); // max val upto each event
        maxVal[0] = events[0][2];

        for (int i = 1; i < n; ++i) {
            maxVal[i] = max(maxVal[i - 1], events[i][2]);
        }

        int maxSum = 0;

        for (int i = 0; i < n; ++i) {
            // take only cur event - (case 1)
            maxSum = max(maxSum, events[i][2]);

            // combine with best possible non-overlapping event - (case 2)
            int idx = f(events, i); 
            if (idx != -1) {
                maxSum = max(maxSum, events[i][2] + maxVal[idx]);
            }
        }

        return maxSum;
    }
};


// Author: Ikramul Hasan Rakib