// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/product-array-puzzle4525

lass Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 1);
        int prefix = 1, suffix = 1;
        
        for(int i = 0; i < n; ++i) {
            res[i] = prefix;
            prefix *= arr[i];
        }
        
        for(int i = n - 1; i >= 0; --i) {
            res[i] *= suffix;
            suffix *= arr[i];
        }
        return res;
    }
};

// Author: Ikramul Hasan Rakib