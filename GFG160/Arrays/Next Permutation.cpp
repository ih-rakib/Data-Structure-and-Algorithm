// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/next-permutation5226

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // next_permutation(arr.begin(), arr.end());

        int n = arr.size();
        int pivot = -1;
        for(int i = n - 2; i >= 0; --i) {
            if(arr[i] < arr[i+1]) {
                pivot = i; break;
            }
        }

        if(pivot == -1) {
            reverse(arr.begin(), arr.end());
        }else {
            for(int i = n - 1; i >= 0; --i) {
                if(arr[i] > arr[pivot]) {
                    swap(arr[i], arr[pivot]); break;
                }
            }
            reverse(arr.begin() + pivot + 1, arr.end());
        }
    }
};

// Author: Ikramul Hasan Rakib
