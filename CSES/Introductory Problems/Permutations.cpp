// https://cses.fi/problemset/task/1070

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; 
    cin >> n;
    if(n == 1) {
        cout << 1;
        return;
    }
    if(n <= 3) {
        cout << "NO SOLUTION"; return;
    }

    for(int i = 2; i <= n; i+=2) {
        cout << i << " ";
    }
    for(int i = 1; i <= n; i+=2) {
        cout << i << " ";
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
         solve();
    }
    return 0;
}