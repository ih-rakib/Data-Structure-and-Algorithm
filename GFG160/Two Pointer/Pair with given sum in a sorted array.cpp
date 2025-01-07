// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/pair-with-given-sum-in-a-sorted-array4940

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int l = 0, r = n - 1, ans = 0;
        
        while(l < r) {
            int sum = arr[l] + arr[r];
            
            if(sum == target) {
                int cntLeft = 1, cntRight = 1;
                
                while(l < r and arr[l] == arr[l+1]) {
                    cntLeft++; l++;
                }
                
                while(l < r and arr[r] == arr[r-1]) {
                    cntRight++; r--;
                }
                
                if(arr[l] == arr[r]) {
                    ans += (cntLeft * (cntLeft - 1)) / 2;
                    break;
                }else {
                    ans += (cntLeft * cntRight);
                }
                
                l++; r--;
            }else if(sum < target) {
                l++;
            }else {
                r--;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib