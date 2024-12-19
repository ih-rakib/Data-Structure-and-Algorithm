// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-bonus-problems/problem/implement-lower-bound

class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int n = arr.size();
        int l = 0, r = n - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if((mid == 0 or arr[mid] > arr[mid-1]) and (mid == n - 1 or arr[mid] > arr[mid + 1])) {
                return arr[mid];
            }

            if(mid < n - 1 and arr[mid] < arr[mid + 1]) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        return -1;
    }
};

// Author: Ikramul Hasan Rakib