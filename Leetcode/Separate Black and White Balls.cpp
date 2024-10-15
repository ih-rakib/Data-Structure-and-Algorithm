// https://leetcode.com/problems/separate-black-and-white-balls/

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        long long ans = 0;
        vector<long long> blackPos;

        for(int i = 0; i < n; ++i){
            if(s[i] == '1') blackPos.push_back(i);
        }

        int k = blackPos.size();
        for(int i = 0; i < k; ++i) {
            ans += abs(blackPos[i] - (n - k + i));
        }
        return ans;
    }
};