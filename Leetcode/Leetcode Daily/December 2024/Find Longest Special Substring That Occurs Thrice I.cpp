// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/

class Solution {
public:
    int maximumLength(string s) {
        int n = s.length(), l = 1, r = n - 1, ans = -1;

        auto ok = [&](int x) {
            vector<int> count(26, 0);
            int start = 0;

            for(int i = 0; i < n; ++i) { 
                while(s[start] != s[i]) start++;
                if(i - start + 1 >= x) count[s[i] - 'a']++;
                if(count[s[i] - 'a'] >= 3) return true;
            }
            return false;
        };

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(ok(mid)) {
                ans = mid;
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

// Author: Ikramul Hasan Rakib