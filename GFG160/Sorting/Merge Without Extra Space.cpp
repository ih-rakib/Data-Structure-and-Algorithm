// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/merge-two-sorted-arrays-1587115620

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int i = n - 1, j = 0;

        while(i >= 0 and j < m) {
            if(a[i] > b[j]) swap(a[i], b[j]);
            i--; j++;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};

// Author: Ikramul Hasan Rakib