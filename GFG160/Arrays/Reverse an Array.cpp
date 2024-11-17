// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/reverse-an-array

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // reverse(arr.begin(), arr.end());

        int n = arr.size();
        for(int i = 0; i < n/2; ++i) {
            swap(arr[i], arr[n-i-1]);
        }
    }
};

// Author: Ikramul Hasan Rakib