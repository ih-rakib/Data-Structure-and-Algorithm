// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-bonus-problems/problem/subarrays-with-k-different-integers

class Solution {
  public:
    int atMostK(vector<int> &arr, int k) {
        int n = arr.size();
        int l = 0, r = 0, ans = 0;
        
        unordered_map<int, int> freq;
        
        while(r < n) {
            freq[arr[r]]++;
            
            while(freq.size() > k) {
                freq[arr[l]]--;
                if(freq[arr[l]] == 0) {
                    freq.erase(arr[l]);   
                }
                
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
  
    int exactlyK(vector<int> &arr, int k) {
        return atMostK(arr, k) - atMostK(arr, k - 1);
    }
};

// Author: Ikramul Hasan Rakib