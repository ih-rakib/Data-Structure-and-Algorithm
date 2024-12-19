// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/kth-missing-positive-number-in-a-sorted-array

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        int cur = 1, i = 0;

        while(k > 0) {
            if(i < n and arr[i] == cur) {
                i++;
            }else {
                k--;
            }
            cur += 1;
        }
        return cur - 1;
    }
}; 

// Author: Ikramul Hasan Rakib