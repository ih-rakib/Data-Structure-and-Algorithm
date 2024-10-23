// https://leetcode.com/problems/longest-happy-string/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string res = "";

        while(!pq.empty()){
            auto [curCount, curChar] = pq.top();
            pq.pop();

            if(res.length() >= 2 and res.back() == curChar and res[res.length() - 2] == curChar) {
                // invalid
                if(pq.empty()) break;

                auto [nextCount, nextChar] = pq.top();
                pq.pop();

                res += nextChar;
                nextCount--;
                if(nextCount > 0) pq.push({nextCount, nextChar});
                pq.push({curCount, curChar});
            }else {
                res += curChar;
                curCount--;
                if(curCount > 0) pq.push({curCount, curChar});
            }
        }

        return res;
    }
};