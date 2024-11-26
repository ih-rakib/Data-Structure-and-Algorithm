// https://leetcode.com/problems/prime-subtraction-operation/

class Solution {
public:
    vector<int> primes;
    
    void sieve(int limit) {
        vector<bool> isPrime(limit, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p <= limit; ++p) {
            if (isPrime[p]) {
                for (int j = p * p; j <= limit; j += p) {
                    isPrime[j] = false;
                }
            }
        }

        for (int p = 2; p <= limit; ++p) {
            if (isPrime[p]) {
                primes.push_back(p);
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        sieve(1007); 

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i]) continue;
            auto it = upper_bound(primes.begin(), primes.end(), nums[i] - nums[i + 1]);
            if (it == primes.end()) return false; 
            nums[i] -= *it;
            if (nums[i] <= 0) return false;
        }
        return true;
    }
};

// Author: Ikramul Hasan Rakib