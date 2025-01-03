// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/fizz-buzz

class Solution {
  public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans; 

        for(int i = 1; i <= n; ++i) {
            if(i % 3 == 0 and i % 5 == 0) {
                ans.push_back("FizzBuzz");
            }else if(i % 3 == 0) {
                ans.push_back("Fizz");
            }else if(i % 5 == 0) {
                ans.push_back("Buzz");
            }else {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};


// Author: Ikramul Hasan Rakib