// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/majority-vote

class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;

        for(int x : arr) freq[x]++;

        vector<int> ans;
        for(auto e : freq) {
            if(e.second > n/3) ans.push_back(e.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Author: Ikramul Hasan Rakib