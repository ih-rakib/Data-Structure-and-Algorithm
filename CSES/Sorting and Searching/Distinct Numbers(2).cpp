// https://cses.fi/problemset/task/1621/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; ++i) cin >> v[i];

    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(i == 0 or v[i]!=v[i-1]){
            ans++;
        }
    }
    cout << ans;
}

int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
         solve();
    }
    return 0;
}