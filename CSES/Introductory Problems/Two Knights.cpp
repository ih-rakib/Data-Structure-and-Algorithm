// https://cses.fi/problemset/task/1072

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;

void solve() {
    // # of ways not attack = # of ways to place two knight - # of ways they attack
    // # of ways to place two knight = k^2 choose 2 (k^2C2) - (total # of cells = k^2)
    // k^2C2 = (k^2(k^2 - 1)) / 2
    // # of ways two knight attack = ? 
    // whenever we get a 2 x 3 or 3 x 2 rectangle, there are two ways they attack each other
    // so, we have to determine how many 2 x 3 and 3 x 2 rectangle there
    // # of ways they attack = 2 * (# 2 x 3 rec + # 3 x 2 rec)
    // # 2 x 3 rec = (k - 1) * (k - 2)
    // # 3 x 2 rec = (k - 2) * (k - 1)
    // ans = (k^2(k^2 - 1)) / 2 - (4 * (k-1) * (k-2))

    ll n; 
    cin >> n;
    
    for(ll k = 1; k <= n; ++k) {
        ll A = (k*k*(k*k -1)) / 2;
        ll B = 4 * (k-1)*(k-2);
        cout << A - B << '\n';
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