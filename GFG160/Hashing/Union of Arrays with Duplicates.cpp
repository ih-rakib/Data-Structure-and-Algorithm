// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/union-of-two-arrays3538

class Solution {
  public:
    int findUnion(vector<int>& a, vector<int>& b) {
        set<int> s;
        for(int x : a) s.insert(x);
        for(int x : b) s.insert(x);
        return s.size();
    }
};

// Author: Ikramul Hasan Rakib