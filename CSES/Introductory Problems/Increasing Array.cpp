// https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n; 
    cin >> n;

    ll max_so_far = -1, ans = 0;

    for(int i = 0; i < n; ++i){
        ll x; 
        cin >> x;

        if(x < max_so_far) {
            ans += max_so_far - x;
        }else {
            max_so_far = x;
        }
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