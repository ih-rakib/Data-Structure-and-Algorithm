// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-bonus-problems/problem/find-all-four-sum-numbers1732

class Solution {
  public:
    // arr[] : int input array of integers
    // target : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        for(int i = 0; i + 3 < n; ++i) {
            if(i > 0 and arr[i] == arr[i-1]) continue;
            
            for(int j = i + 1; j + 2 < n; ++j) {
                if(j > i + 1 and arr[j] == arr[j-1]) continue;
                
                int l = j + 1, r = n - 1;
                
                while(l < r) {
                    long long sum = (long long) arr[i] + arr[j] + arr[l] + arr[r];
                    if(sum == target) {
                        res.push_back({arr[i], arr[j], arr[l], arr[r]});
                        while(l < r and arr[l] == arr[l+1]) l++;
                        while(l < r and arr[r] == arr[r-1]) r--;
                        l++; r--;
                    }else if(sum < target) {
                        l++;
                    }else {
                        r--;
                    }
                }
            }
        }
        return res;
    }
};

// Author: Ikramul Hasan Rakib