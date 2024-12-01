// https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;

        for(int x : arr) {
            if(seen.count(x * 2) || (x % 2 == 0 && seen.count(x / 2))) return true;
            seen.insert(x);
        }

        return false;
    }

    // bool checkIfExist(vector<int>& arr) {
    //     unordered_map<int, int> mp;

    //     for(int i = 0; i < arr.size(); ++i) {
    //         mp.insert({arr[i], i});
    //     }

    //     for(int i = 0; i < arr.size(); ++i) {
    //         if(mp.find(2*arr[i]) != mp.end() and mp[2*arr[i]] != i) return true;
    //     }

    //     return false;
    // }


    // bool checkIfExist(vector<int>& arr) {
    //     sort(arr.begin(), arr.end());

    //     for(int i = 0; i < arr.size(); ++i) {
    //         int z = binary_search(arr.begin(), arr.end(), 2*arr[i]);

    //         if(z) {
    //             auto it = lower_bound(arr.begin(), arr.end(), 2*arr[i]);
    //             if(it != arr.begin() + i) return true;
    //         }
    //     }
    //     return false;
    // }
};

// Author: Ikramul Hasan Rakib