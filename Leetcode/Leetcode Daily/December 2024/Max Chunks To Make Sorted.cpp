// https://leetcode.com/problems/max-chunks-to-make-sorted/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int max_so_far = -1, ans = 0;
        for(int i = 0; i < n; ++i) {
            max_so_far = max(arr[i], max_so_far);

            if(max_so_far == i) {
                ans++;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib