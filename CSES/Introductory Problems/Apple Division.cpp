// https://cses.fi/problemset/task/1623

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;

void solve() {
  int n; 
  cin >> n;

  vector<int> v(n);

  for(int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  ll ans = 1e18;
  for(int mask = 0; mask < (1<<n); ++mask) {
    ll A = 0, B = 0;
    for(int i = 0; i < n; ++i) {
        if(mask & (1 << i)){ // set bit
            A += v[i];
        }else {
            B += v[i];
        }
    }
    ans = min(ans, abs(A - B));
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