// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/largest-subarray-of-0s-and-1s

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        int ans = 0, sum = 0;
        unordered_map<int, int> sumIdx;
        sumIdx[0] = -1;
        
        for(int i = 0; i < n; ++i) {
            sum += (arr[i] == 0 ? -1 : 1);
            
            if(sumIdx.find(sum) != sumIdx.end()) {
                ans = max(ans, i - sumIdx[sum]);
            }else {
                sumIdx[sum] = i;
            }
        }
        return ans;
    }
};


// Author: Ikramul Hasan Rakib