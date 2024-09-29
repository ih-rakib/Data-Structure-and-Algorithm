// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = nums[0], minProduct = nums[0], result = nums[0];

        for(int i = 1; i < n; ++i) {
            if(nums[i] < 0){
                swap(maxProduct, minProduct);
            }
            
            maxProduct = max(nums[i], nums[i] * maxProduct);
            minProduct = min(nums[i], nums[i] * minProduct); // two negative numbers result in positive via multiplying
            
            result = max(result, maxProduct);
        }
        return result;
    }
};