// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/smallest-positive-missing-number-1587115621

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        /*
        set<int> s;

        for(int x : arr) {
            if(x > 0) s.insert(x);
        }

        int i = 1;
        for(int x : s) {
            if(x != i) return i;
            i++;
        }
        return i;
        */

       int n = arr.size();
        
       // place each element in it's correct index. like [1 in index 0, 2 in index 1...] 
       for(int i = 0; i < n; ++i) {
           while(arr[i] > 0 && arr[i] < n && arr[arr[i] - 1] != arr[i]){
               swap(arr[i], arr[arr[i] - 1]);
           }
       }

       for(int i = 0; i < n; ++i) {
           if(arr[i] != i+1) return i + 1;
       }
       return n + 1;
    }
};

// Author: Ikramul Hasan Rakib