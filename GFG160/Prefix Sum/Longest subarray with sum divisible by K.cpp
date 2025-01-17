// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-bonus-problem/problem/longest-subarray-with-sum-divisible-by-k1259

class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        unordered_map<long long, long long> modId;
        modId[0] = -1;
        
        long long psum = 0, ans = 0, n = arr.size();
        
        for(int i = 0; i < n; ++i) {
            psum += arr[i];
            int modVal = (psum % k + k) % k;
            
            if(modId.find(modVal) != modId.end()) {
                ans = max(ans, i - modId[modVal]);
            }else {
                modId[modVal] = i;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib