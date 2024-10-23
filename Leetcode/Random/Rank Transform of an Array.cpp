// https://leetcode.com/problems/rank-transform-of-an-array/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        int n = arr.size();

        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        unordered_map<int, int> m;

        for(int i = 0; i < temp.size(); ++i) {
            m[temp[i]] = i + 1;
        }

        vector<int> res;
        for(int x : arr) {
            res.push_back(m[x]);
        }
        return res;
    }
};