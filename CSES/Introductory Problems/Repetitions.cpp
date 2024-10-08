// https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int ans = 0, len = 0;
    for(int i = 0; i < (int)s.length(); ++i){
        if(i == 0 or s[i] == s[i-1]){
            len++;
        }else {
            len = 1;
        }
        ans = max(ans, len);
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) {
         solve();
    }
}