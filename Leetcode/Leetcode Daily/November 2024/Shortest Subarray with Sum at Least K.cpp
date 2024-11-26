// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n + 1, start = 0;
        vector<int> psum(n+1, 0);
        deque<int> dq;
        
        for(int i = 0; i < n; ++i) psum[i+1] = psum[i] + nums[i]; // psum will store index of prefix sum in increasing/non-decreasing order

        for(int i = 0; i <= n; ++i) {
            // Check if there's a valid subarray from the deque
            while(!dq.empty() && psum[i] - psum[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            // Maintain increasing order of prefix sums in the deque
            while(!dq.empty() && psum[i] <= psum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return ans == n + 1 ? -1 : ans;
    }
};

// Author: Ikramul Hasan Rakib

/*

# Input: nums = [84, -37, 32, 40, 95], k = 167

- psum = [0, 84, 47, 79, 119, 214]

1. i = 0:  
   - psum[0] = 0
   - The deque is empty, so simply add index 0 to the deque:  
     dq = [0].

2. i = 1:  
   - psum[1] = 84
   - add index 1 to the deque because psum[1] is greater than psum[0]:  
     dq = [0, 1].

3. i = 2:  
   - psum[2] = 47
   - Since psum[2] = 47 is less than psum[1] = 84, pop index 1 from the deque (because a smaller prefix sum((subtracting 84, therefore smaller)) at index 2 won't be useful for future calculations), so remove 1.  
   - Now, dq = [0] and add 2 to the deque:  
     dq = [0, 2].

4. i = 3:  
   - psum[3] = 79
   - add index 3 to the deque because psum[3] = 79 is greater than psum[2] = 47:  
     dq = [0, 2, 3].

5. i = 4:  
   - psum[4] = 119
   - add index 4 to the deque because psum[4] = 119 is greater than psum[3] = 79:  
     dq = [0, 2, 3, 4].

6. i = 5 (psum[5] = 214):  
   Now check the subarray sums:
   - Check if the subarray sum from the front of the deque is >= k:
     - 214 - psum[dq.front()] = 214 - psum[0] = 214 - 0 = 214 >= 167 → Valid subarray.
       - pop index 0 and update ans = min(ans, 5 - 0) = 5.  
       - The deque is now dq = [2, 3, 4].
     - 214 - psum[dq.front()] = 214 - psum[2] = 214 - 47 = 167 >= 167 → Valid subarray.
       - pop index 2 and update ans = min(ans, 5 - 2) = 3.  
       - The deque is now dq = [3, 4].
     - 214 - psum[dq.front()] = 214 - psum[3] = 214 - 79 = 135 < 167 → No further valid subarrays from the front, so stop popping.
   
   - Finally, add index 5 to the deque:  
     dq = [3, 4, 5].

# Final Answer:
- The smallest subarray with a sum of at least 167 is from index 2 to index 4, which has the sum 32 + 40 + 95 = 167.  
  Therefore, ans = 3.

---

# Key Points:
- The key operation here is that whenever we encounter a new prefix sum (psum[i]), we try to find subarrays by checking whether the difference between the current prefix sum and the previous sums (stored in the deque) is greater than or equal to k. If it is, we pop elements from the deque to maintain a valid subarray. 
- We also make sure to keep the deque ordered in increasing order of prefix sums, so that we always try to find the smallest subarray from the left-most valid starting index.

*/

/*

bruteforce:

int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n + 1;
        
        for(int i = 0; i < n; ++i) {
            int sum = 0;
            for(int j = i; j < n; ++j) {
                sum += nums[j];
                if(sum >= k) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == n+1 ? -1 : ans;
    }

*/