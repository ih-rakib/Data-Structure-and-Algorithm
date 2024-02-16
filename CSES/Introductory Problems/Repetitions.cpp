#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s; 
    cin >> s;
    int len = 1, ans = 1;
    
    for(int i = 1; i < (int)s.length(); ++ i) {
        if(s[i] == s[i-1]) {
            len++;
        }else{
            len = 1;
        }
        ans = max(ans, len);
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
         solve();
    }
    return 0;
}