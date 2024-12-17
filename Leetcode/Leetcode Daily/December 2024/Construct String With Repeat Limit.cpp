// https://leetcode.com/problems/construct-string-with-repeat-limit/

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);

        for(char c : s) freq[c - 'a']++;

        priority_queue<pair<char, int>> pq;

        for(int i = 0; i < 26; ++i) {
            if(freq[i] > 0) {
                pq.push({'a' + i, freq[i]});
            }
        }

        string ans = "";
        while(!pq.empty()) {
            auto [cur, cnt] = pq.top();
            pq.pop();

            int take = min(cnt, repeatLimit);
            ans.append(take, cur);

            if(cnt > take) {
                if(pq.empty()) break;

                auto [nextChar, nextCnt] = pq.top();
                pq.pop();
                ans.push_back(nextChar);
                pq.push({cur, cnt - take});

                if(nextCnt > 1) {
                    pq.push({nextChar, nextCnt - 1});
                }
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib