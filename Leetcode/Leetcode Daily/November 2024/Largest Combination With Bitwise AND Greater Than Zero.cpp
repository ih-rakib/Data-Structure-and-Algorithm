// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();

        int ans = 0;
        for(int bit = 0; bit < 32; ++bit) {
            int cnt = 0;

            // count how many numbers there with current bit set
            for(int num : candidates) {
                if(num & (1 << bit)) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib

/*

    bruteforce:

    class Solution {
    public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int ans = 0;
        for(int mask = 1; mask < (1 << n); ++mask) {
            int subsetAnd = -1;
            int subsetSize = 0;
            
            for(int i = 0; i < n; ++i){
                if(mask & (1 << i)) {
                    if(subsetAnd == -1) {
                        subsetAnd = candidates[i];
                    }else {
                        subsetAnd &= candidates[i];
                    }
                    subsetSize++;
                }
            }
            if(subsetAnd > 0) {
                ans = max(ans, subsetSize);
            }
        }
        return ans;
    }
};

*/