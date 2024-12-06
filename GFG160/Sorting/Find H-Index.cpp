// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/find-h-index--165609

class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // i'th paper need at least i+1 citation (i from 0)
        sort(citations.begin(), citations.end(), greater<int> ());
        int ans = 0;
        for(int i = 0; i < citations.size(); ++i) {
            if(citations[i] >= i + 1) {
                ans++;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib