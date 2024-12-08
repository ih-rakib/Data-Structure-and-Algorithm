// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/overlapping-intervals--170633

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // [1, 3], [2, 4] => [1, 4]: 3 > 2
        int n = arr.size(); 
        if(n == 0) return {};

        sort(arr.begin(),arr.end());

        vector<vector<int> > ans;

        ans.push_back(arr[0]);

        for(int i = 1; i < n; ++i) {
            int x = arr[i][0];
            int y = ans.back()[1];
            
            if(x <= y) {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }else {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib