// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-bonus-problem/problem/sub-array-sum-divisible-by-k2617

class Solution {
  public:
    // Function to count the number of subarrays with a sum that is divisible by K
    int subCount(vector<int>& arr, int k) {
        unordered_map<int, int> modCount;
        modCount[0] = 1;
        
        long long psum = 0, ans = 0;
        
        for(int x : arr) {
            psum += x;
            int modVal = (psum % k + k) % k;
            
            if(modCount.find(modVal) != modCount.end()) {
                ans += modCount[modVal];
            }
            
            modCount[modVal]++;
        }
        return ans;
    }
};


// Author: Ikramul Hasan Rakib