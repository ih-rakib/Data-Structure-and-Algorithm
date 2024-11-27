// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/last-moment-before-all-ants-fall-out-of-a-plank

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mxLeft = 0, mxRight = 0;

        for(int x : left) {
            mxLeft = max(mxLeft, x);
        }

        for(int x : right) {
            mxRight = max(mxRight, n - x);
        }

        return max(mxLeft, mxRight);
    }
};

// Author: Ikramul Hasan Rakib

/*

    ant at pos p in left array will take p seconds to fall out
    ant at pos p in right array will take n - p seconds to fall out
    last moment is when last ant fall out

    max time taken for ant in left and right array

*/