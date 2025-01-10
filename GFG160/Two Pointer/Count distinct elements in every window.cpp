// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-distinct-elements-in-every-window

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> res;
        
        int l = 0, r = 0;
        
        while(r < n) {
            freq[arr[r]]++;
            
            if(r - l + 1 == k) {
                res.push_back(freq.size());
                
                freq[arr[l]]--;
                if(freq[arr[l]] == 0) {
                    freq.erase(arr[l]);   
                }
                l++;
            }
            r++;
        }
        return res;
    }
};

// Author: Ikramul Hasan Rakib