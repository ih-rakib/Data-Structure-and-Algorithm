// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> res;

        for(string s: folder) {
            if(res.empty() or s.find(res.back() + "/") != 0) {
                res.push_back(s);
            }
        }
        return res;
    }
};