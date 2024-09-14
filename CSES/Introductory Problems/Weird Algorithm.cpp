// https://cses.fi/problemset/task/1068

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n; 
    cin >> n;

    while(n > 1) {
        cout << n << " ";
        if(n & 1) {
            n = (n * 3) + 1;
        }else {
            n = n / 2;
        }
    }
    cout << 1;
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