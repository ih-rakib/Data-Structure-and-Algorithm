// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-bonus-problems/problem/largest-number-formed-from-an-array1117

class Solution {
  public:
    string findLargest(vector<int> &arr) {
        vector<string> nums;

        for(int x : arr) nums.push_back(to_string(x));

        sort(nums.begin(), nums.end(), [](string &a, string &b) {
            return a + b > b + a; // "5" + "34" > "34" + "5"
        });

        if(nums[0] == "0") return "0";

        string res = "";

        for(string s : nums) res += s;
        return res;
    }
};

// Author: Ikramul Hasan Rakib