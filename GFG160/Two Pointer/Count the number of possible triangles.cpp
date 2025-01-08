// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-possible-triangles-1587115620

class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if(n < 3) return 0;
        int ans = 0;
        for(int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while(i < j) {
                if(arr[i] + arr[j] > arr[k]) {
                    ans += (j - i);
                    j--;
                }else {
                    i++;
                }
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib