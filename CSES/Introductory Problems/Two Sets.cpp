// https://cses.fi/problemset/task/1092

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;

void solve() {
   ll n;
   cin >> n;
   ll sum = (n * (n + 1)) / 2;

   if(sum & 1) {
    cout << "NO\n"; return;
   }

   ll target = sum / 2;

    cout << "YES\n";

    set<ll> s1, s2;
    for(int i = 1; i <= n; ++i) {
        s1.insert(i);
    }

    int val = n;

    while(s1.count(target) == 0) {
        s2.insert(val);
        s1.erase(val);
        target -= val;
        val--;
    }
    s1.erase(target);
    s2.insert(target);

    cout << s1.size() << '\n';
    for(int x : s1) {
        cout << x << " ";
    }
    cout << '\n' << s2.size() << '\n';
    for(int x : s2) {
        cout << x << " ";
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