// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/peak-element

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int l = 0, r = arr.size() - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            bool isPeak = (mid == 0 or arr[mid] > arr[mid-1]) and (mid == arr.size() - 1 or arr[mid] > arr[mid+1]);

            if(isPeak) return mid;

            if(mid > 0 and arr[mid-1] > arr[mid]) {
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

// Author: Ikramul Hasan Rakib