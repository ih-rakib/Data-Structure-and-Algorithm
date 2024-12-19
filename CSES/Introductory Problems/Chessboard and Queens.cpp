// https://cses.fi/problemset/task/1624

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 8;
char board[N][N];
int diagLeft[2*N - 1], diagRight[2*N - 1], column[N];

int f(int row) {
    if(row == N) {
        return 1;
    }

    int ans = 0;

    for(int col = 0; col < N; ++col) {
       if(board[row][col] != '*' && column[col] == 0 && diagLeft[row - col + N - 1] == 0 && diagRight[row + col] == 0) {
        column[col] = diagLeft[row - col + N - 1] = diagRight[row + col] = 1;
        ans += f(row + 1);
        column[col] = diagLeft[row - col + N - 1] = diagRight[row + col] = 0;
       }
    }
    return ans;
}

void solve() {
    for(int i = 0; i < N; ++i) cin >> board[i];

    cout << f(0);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) {
         solve();
    }
}

// Author: Ikramul Hasan Rakib