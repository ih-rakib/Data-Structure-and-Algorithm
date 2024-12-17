// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/k-th-element-of-two-sorted-array1317

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        int cur = 0;

        for(int z = 1; z <= k; ++z) {
            if(j >= m or (i < n and a[i] < b[j])) {
                cur = a[i];
                i++;
            }else {
                cur = b[j];
                j++;
            }
        }
        return cur;
    }
};

// Author: Ikramul Hasan Rakib