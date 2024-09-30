// https://cses.fi/problemset/task/1650

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int limit = 2e5 + 7;
ll prefXOR[limit];


void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int i = 1; i <= n; ++i) cin >> v[i];

    for(int i = 1; i <= n; ++i) prefXOR[i] = prefXOR[i-1] ^ v[i];

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << (prefXOR[b] ^ prefXOR[a-1]) << '\n';
    }
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