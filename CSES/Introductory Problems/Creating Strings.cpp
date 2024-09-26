// https://cses.fi/problemset/task/1622

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    vector<string> v;

    do {
        v.push_back(s);
    }while(next_permutation(s.begin(), s.end()));

    cout << v.size() << '\n';

    for(auto s : v) {
        cout << s << '\n';
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