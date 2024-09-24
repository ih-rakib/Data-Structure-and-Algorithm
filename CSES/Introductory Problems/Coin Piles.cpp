// https://cses.fi/problemset/task/1754

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;

void solve() {
   int n; 
   cin >> n;
   
   for(int i = 0; i < n; ++i){
    int a, b;
    cin >> a >> b;
    int l = min(a, b);
    int r = max(a, b);

    if((l + r) % 3 == 0 and 2*l >= r) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
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