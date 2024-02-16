#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    set<int> s;
    
    for(int i = 0; i < n; ++i) {
        int x; cin >> x; 
        s.insert(x);
    }
    cout << (int) s.size();
}

int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
         solve();
    }
    return 0;
}