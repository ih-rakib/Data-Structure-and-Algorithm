// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-bonus-problem/problem/count-quadruplets-with-given-sum

class Solution {
  public:
    int countSum(vector<int>& arr, int target) {
        unordered_map<int, vector<pair<int,int>>> sumMap;
        int ans = 0;
        int n = arr.size();
        
        for(int i = 0; i + 1 < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                sumMap[arr[i] + arr[j]].push_back({i, j});
            }
        }
        
        for(int i = 0; i + 1 < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int comp = target - (arr[i] + arr[j]);
                if(sumMap.find(comp) != sumMap.end()) {
                    for(auto p : sumMap[comp]) {
                        if(p.first > j) ans++;
                    }
                }
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib