// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<pair<int, int> > events;

        for(auto &interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            events.push_back({start, 1});
            events.push_back({end+1, -1});
        }

        sort(events.begin(), events.end());

        int ans = 0, current = 0;

        for(auto &[x, y] : events){
            current += y;
            ans = max(ans, current);
        }
        return ans;
    }
};