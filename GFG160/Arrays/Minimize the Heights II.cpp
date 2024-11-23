// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/minimize-the-heights3351

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();

        if(n == 1) return 0;

        sort(arr.begin(), arr.end());

        int ans = arr[n-1] - arr[0];
        for(int i = 0; i + 1 < n; ++i) {
            int smallest = min(arr[0] + k, arr[i+1] - k);
            int largest = max(arr[i] + k, arr[n-1] - k);
            if(smallest < 0 || largest < 0) continue;
            ans = min(ans, largest - smallest);
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib

/*

    increase some by k and decrease some by k
    so increase by k : (from 0 to i)
    decrease by k: (from i + 1 to n)

*/