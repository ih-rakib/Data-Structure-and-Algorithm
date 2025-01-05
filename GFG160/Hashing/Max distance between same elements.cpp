// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-bonus-problem/problem/max-distance-between-same-elements

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> first;
        int ans = 0;
        
        for(int i = 0; i < arr.size(); ++i) {
            if(first.find(arr[i]) == first.end()) {
                first[arr[i]] = i;   
            }else {
                ans = max(ans, i - first[arr[i]]);
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib