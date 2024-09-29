// https://cses.fi/problemset/task/1643/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; 
    cin >> n;
    vector<int> v(n);

    ll ans = LLONG_MIN, cur = 0;
    for(int i = 0; i < n; ++i) cin >> v[i];

    for(int i = 0; i < n; ++i) {
        cur = max(1LL * cur + v[i], 1LL * v[i]);
        ans = max(ans, cur);
    }
    cout << ans << '\n';
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