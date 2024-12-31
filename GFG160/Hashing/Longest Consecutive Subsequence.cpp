// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/longest-consecutive-subsequence2449

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        int ans = 0;
        
        for(int x : s) {
            if(s.find(x - 1) == s.end()) {
                int curNum = x;
                int curLen = 1;
                
                while(s.find(curNum + 1) != s.end()) {
                    curNum++;
                    curLen++;
                }
                
                ans = max(ans, curLen);
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib