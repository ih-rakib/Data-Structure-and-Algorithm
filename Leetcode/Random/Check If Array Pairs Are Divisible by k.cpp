// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> remCount(k, 0);

        for(int num : arr) {
            int rem = ((num % k) + k) % k; // // This ensures the remainder is non-negative
            remCount[rem]++;
        }

        // reminder count of 0 has to be even to be paired with itself
        if(remCount[0] & 1) {
            return false;
        }

        for(int rem = 1; rem <= k/2; ++rem) {
            if(remCount[rem] != remCount[k-rem]){
                return false;
            }
        }
        return true;
    }
};

// if a number divided by k has reminder r, it can be paired with a number having reminder k-r, thus their sum becomes divisible by k