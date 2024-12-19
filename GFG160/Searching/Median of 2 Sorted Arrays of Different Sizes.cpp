// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-bonus-problems/problem/implement-lower-bound

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        vector<double> all;

        for(int x : a) all.push_back(x);
        for(int x : b) all.push_back(x);

        sort(all.begin(), all.end());

        int n = all.size();

        return (n & 1 ? all[n/2] : (all[n/2] + all[(n-1)/2])/2);
    }
};

// Author: Ikramul Hasan Rakib