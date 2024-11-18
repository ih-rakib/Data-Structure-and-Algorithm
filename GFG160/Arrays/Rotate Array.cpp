// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/rotate-array-by-n-elements-1587115621

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d %= n;
        
        // 1,2,3,4,5 => 3,4,5,1,2
        reverse(arr.begin(), arr.begin() + d); // 2,1,3,4,5
        reverse(arr.begin() + d, arr.end()); // 2,1,5,4,3
        reverse(arr.begin(), arr.end()); // 3,4,5,1,2
    }

    // void rotateArr(vector<int>& arr, int d) {
    //     int n = arr.size();
    //     d %= n;

    //     vector<int> ans(n);
    //     for(int i = 0; i < n; ++i) {
    //         ans[i] = arr[(i + d ) % n];
    //     }
        
    //     arr = ans;
    // }
};

// Author: Ikramul Hasan Rakib