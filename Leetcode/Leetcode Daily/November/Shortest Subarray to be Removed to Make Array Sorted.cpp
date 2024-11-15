// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;

        while (left + 1 < n && arr[left] <= arr[left + 1]) { // sorted prefix
            left++;
        }

        if (left == n - 1) return 0; // already sorted

        while (right - 1 >= 0 && arr[right] >= arr[right - 1]) { // sorted suffix
            right--;
        }

        int ans = min(n - left - 1, right); // can remove min(prefix, suffix)

        for (int i = 0; i <= left; ++i) {
            while (right < n && arr[i] > arr[right]) { // for each in prefix, trying to merge suffix
                right++;
            }

            if (right < n) {
                ans = min(ans, right - i - 1); // min len of subarray to remove 
            }
        }

        return ans;
    }
};


// Author: Ikramul Hasan Rakib

/*

    why right - i - 1?

    [2, 3, 10, 2, 5]
    [0, 1, 2,  3, 4]

    Sorted prefix: [2, 3, 10]
    Sorted suffix: [2, 5]

    first iteration: i = 0, r = 3: 3 - 0 - 1 = 2; removing [3, 10] stays: [2, 2, 5] 
    second iteration: i = 1, right = 4: 4 - 1 - 1 = 2; removing [10, 2] stays: [2, 3, 5]
    third iteration: i = 2, right = 5, out of bound 

*/

/*

    bruteforce:

    bool isSorted(vector<int> &arr) {
        int n = arr.size();
        for(int i = 1; i < n; ++i) {
            if(arr[i] < arr[i-1]) return false;
        }
        return true;
    }

    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int ans = n;

        if (isSorted(arr)) return 0;

        // iterate over all subarray
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                vector<int> remainingArr;
                
                for(int k = 0; k < i; ++k) remainingArr.push_back(arr[k]);
                for(int k = j+1; k < n; ++k) remainingArr.push_back(arr[k]);

                if(isSorted(remainingArr)) {
                    ans = min(ans, j - i + 1);
                }
            }
        }
        return ans == n ? 0 : ans;
    }

*/