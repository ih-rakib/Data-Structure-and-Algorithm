// https://cses.fi/problemset/task/1618

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;

    int ans = 0;
    for(int i = 5; i <= n; i *= 5) {
        ans += n/i;
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