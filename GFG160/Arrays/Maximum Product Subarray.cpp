// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/maximum-product-subarray3604

class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        if(n == 0) return 0;

        int maxProduct = arr[0], minProduct = arr[0], ans = arr[0];

        for(int i = 1; i < n; ++i) {
            if(arr[i] < 0) {
                swap(maxProduct, minProduct);
            }

            maxProduct = max(arr[i], arr[i] * maxProduct);
            minProduct = min(arr[i], arr[i] * minProduct);
            ans = max(ans, maxProduct);
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib

/*

    negative * negative = positive
    arr[i] < 0 - neg
    minProduct < 0 - neg

    arr[i] * minProduct = neg * neg = positvie (possible)

*/