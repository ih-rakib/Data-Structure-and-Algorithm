// https://leetcode.com/problems/special-array-ii/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> psum(n + 1, 0);
        psum[0] = 1;
        for(int i = 1; i < n; ++i) {
            if(nums[i] % 2 == nums[i-1] % 2) {
                psum[i] = 1;
            }else {
                psum[i] = psum[i-1] + 1;
            }
        }

        vector<bool> res;
        for(auto &q : queries) {
            int s = q[0], e = q[1];
            int l = e - s + 1;
            if(psum[e] >= l) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};


// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size();
//         vector<int> transition(n - 1, 0);
//         for (int i = 0; i + 1 < n; ++i) {
//             transition[i] = (nums[i] % 2 != nums[i + 1] % 2);
//         }

//         vector<int> prefTrans(n - 1, 0);
//         prefTrans[0] = transition[0];
//         for (int i = 1; i < n - 1; ++i) {
//             prefTrans[i] = prefTrans[i - 1] + transition[i];
//         }

//         vector<bool> res;
//         for (auto& q : queries) {
//             int from = q[0], to = q[1];
//             if (to == from) {
//                 res.push_back(true);
//                 continue;
//             }
//             int cnt = prefTrans[to - 1] - (from > 0 ? prefTrans[from - 1] : 0);
//             res.push_back(cnt == to - from);
//         }
//         return res;
//     }
// };

// Author: Ikramul Hasan Rakib