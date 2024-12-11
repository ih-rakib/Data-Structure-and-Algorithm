// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-bonus-problems/problem/attend-all-meetings

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        int n = arr.size(); 
        if(n <= 1) return true;

        sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        for(int i = 1; i < n; ++i) {
            if(arr[i][0] < arr[i-1][1]) return false;
        }
        return true;
    }
};

// Author: Ikramul Hasan Rakib