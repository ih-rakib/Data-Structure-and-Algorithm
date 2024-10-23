// https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string, int> seq;

        int l = 0, r = 0;
        vector<string> res;

        while(r < n) {
            if(r - l + 1 == 10) {
                string cur = s.substr(l, 10);
                seq[cur]++;

                if(seq[cur] == 2) {
                    res.push_back(cur);
                }
                l++;
            }

            r++;
        }
        return res;
    }
};