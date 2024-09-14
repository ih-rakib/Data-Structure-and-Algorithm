// https://cses.fi/problemset/task/1617

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;

void solve() {
    ll n; 
    cin >> n;

    ll ans = 1;
    for(int i = 1; i <= n; ++i) {
        ans = (ans * 2) % mod;
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