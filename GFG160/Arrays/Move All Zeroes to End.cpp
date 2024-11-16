// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/move-all-zeroes-to-end-of-array0751

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();

        int k = 0;
        for(int i = 0; i < n; ++i) {
            if(arr[i] != 0) {
                arr[k++] = arr[i];
            }
        }

        for(int i = k; i < n; ++i) arr[i] = 0;
    }
};

// Author: Ikramul Hasan Rakib