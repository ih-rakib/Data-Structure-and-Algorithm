// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/search-in-a-rotated-array4618

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int l = 0, r = n - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(arr[mid] == key) return mid;

            // check if left part of arr is sorted
            if(arr[l] <= arr[mid]) {
                if(arr[l] < key and key < arr[mid]) {
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
            }else {
                if(arr[mid] <= key and key <= arr[r]) {
                    l = mid + 1;
                }else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Author: Ikramul Hasan Rakib