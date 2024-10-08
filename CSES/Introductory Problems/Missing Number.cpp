// https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n; 
    cin >> n;

    ll total = 0;
    for(int i = 0; i < n - 1; ++i) {
        int x; cin >> x; total += x;
    }

    ll sum = n * (n + 1) / 2;
    cout << sum - total;
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