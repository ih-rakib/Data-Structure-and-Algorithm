// https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        // 1, 2, 3 --> 1, 3, 2
        for(int i = n-2; i >= 0; --i){
            if(nums[i] < nums[i+1]){
                pivot = i; break; // this has to be swapped/shifted to right so that larger element can come here to get the larger permutation (next permutation of current one)
            }
        }

        if(pivot == -1) { // eg : [5,4,3,2,1] so next to it will be : [1,2,3,4,5]
            reverse(nums.begin(), nums.end());
        }else {
            for(int i = n - 1; i >= 0; --i){
                if(nums[i] > nums[pivot]){
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
            reverse(nums.begin()+pivot+1, nums.end()); // reversing elements after pivot to make it smaller
        }
    }
};