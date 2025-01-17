// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-bonus-problem/problem/number-of-times-graph-cuts-x-axis

class Solution {
  public:
    int touchedXaxis(vector<int>& arr) {
        int pos = 0, cross = 0, prev = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; ++i) {
            pos += arr[i];
            
            if(pos == 0) {
                cross++;
            }else if((prev > 0 and pos < 0) or (prev < 0 and pos > 0)) {
                cross++;
            }
            prev = pos;
        }
        return cross;
    }
};

// Author: Ikramul Hasan Rakib