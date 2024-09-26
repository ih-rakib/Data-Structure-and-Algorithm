#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    unordered_map<char, int> freq;

    for(char c : s) {
        freq[c]++;
    }

    string first, middle;
    int oddCount = 0;

    for (auto it: freq) {
        char ch = it.first;
        int count = it.second;

        if(count & 1) { // odd count of ch
            oddCount++;
            middle += ch;
        }

        first += string(count/2, ch);
    }

    if(oddCount > 1) {
        cout << "NO SOLUTION\n"; return;
    }

    string second = string(first.rbegin(), first.rend());
    string res = first + middle + second;

    cout << res << '\n';
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