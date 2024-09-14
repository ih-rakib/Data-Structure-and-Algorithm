// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> all;

        for(int i = 0; i < nums1.size(); ++i) {
            all.push_back(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); ++i) {
            all.push_back(nums2[i]);
        }

        sort(all.begin(), all.end());

        // median : 
        //  if n = odd: n/2th element is the median
        //  if n = even: (n/2 and (n-1)/2th element) / 2 

        int n = all.size();

        return (n & 1 ? all[n/2] : (all[n/2] + all[(n-1)/2])/2);

        // if (n & 1 == true) this means n is odd
    }
};