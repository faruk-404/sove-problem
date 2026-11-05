#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#define dbg_arr(...)
#define dbg_range(...)
#define dbg_grid(...)
#define dbg_time(...)
#endif

#define nl '\n'
#define nf cout << '\n'
#define ll long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()
const int N = 3e5 + 5;
int dp[N];

int teranacci(int n) {
    if (n < 2) return n;
    if (n < 4) return n - 1;
    int& r = dp[n];
    if (r != -1) return r;
    r = teranacci(n - 1) + teranacci(n - 2) + teranacci(n - 3) + teranacci(n - 4);
    return r;
}

void solve() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << teranacci(n) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}