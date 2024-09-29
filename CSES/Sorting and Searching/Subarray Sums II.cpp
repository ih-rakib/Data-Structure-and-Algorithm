// https://cses.fi/problemset/task/1661
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n, x; 
    cin >> n >> x;
 
    vector<int> v(n);
 
    for(int i = 0; i < n; ++i) cin >> v[i];
 
    map<ll, int> prefSumCount;
    prefSumCount[0] = 1;
    ll curSum = 0, ans = 0;
 
    for(int i = 0; i < n; ++i) {
        curSum += v[i];
        ll target = curSum - x;
        ans += prefSumCount[target];
        prefSumCount[curSum]++;
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
