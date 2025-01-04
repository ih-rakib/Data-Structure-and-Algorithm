// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-all-triplets-with-given-sum-in-sorted-array

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size(), ans = 0;
        
        for(int i = 0; i + 2 < n; ++i) {
            int j = i + 1, k = n - 1;
            
            while(j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                
                if(sum == target) {
                    if(arr[j] == arr[k]) {
                        int x = k - j + 1;
                        ans += (x * (x - 1) / 2);
                        break;
                    }else {
                        int cntJ = 1, cntK = 1;
                        
                        while(j + 1 < k and arr[j] == arr[j + 1]) {
                            cntJ++; j++;
                        }
                        
                        while(k - 1 > j and arr[k] == arr[k - 1]) {
                            cntK++; k--;
                        }
                        
                        ans += (cntJ * cntK);
                        j++; k--;
                    }
                }else if(sum < target) {
                    j++;
                }else {
                    k--;
                }
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib