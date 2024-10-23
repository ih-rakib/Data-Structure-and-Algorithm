// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> A;
        for(int &x : nums1) A.push_back(x);
        for(int &x : nums2) A.push_back(x);

        sort(A.begin(), A.end());
        int n = A.size();

        if(n % 2 == 1){
            return A[n/2];
        }else {
            return (A[n/2] + A[(n-1)/2]) / 2;
        }
    }
};