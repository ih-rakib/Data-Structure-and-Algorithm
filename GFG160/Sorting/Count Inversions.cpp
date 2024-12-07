// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/inversion-of-array-1587115620

class Solution {
  public:
    int cnt = 0;

    void mergeAndCount(vector<int> &arr, int s, int e) {
        int mid = s + (e - s) / 2;
        vector<int> temp;

        int i = s, j = mid + 1;

        while(i <= mid and j <= e) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }else {
                temp.push_back(arr[j]);
                j++;
                cnt += (mid - i + 1);
            }
        }

        while(i <= mid) temp.push_back(arr[i]);
        while(j <= e) temp.push_back(arr[j]);

        for(int i = s; i <= e; ++i) {
            arr[i] = temp[i - s];
        }
    }

    void mergeSort(vector<int> &arr, int s, int e) {
        if(s >= e) return;

        int mid = s + (e - s) / 2;

        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);
        mergeAndCount(arr, s, e);
    }

    int inversionCount(vector<int> &arr) {
        mergeSort(arr, 0, arr.size());
        return cnt;
    }
};

// Author: Ikramul Hasan Rakib