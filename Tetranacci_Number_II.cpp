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

void solve() {
    int n;
    cin >> n;
    ll dp[n];
    dp[0] = 0, dp[1] = dp[2] = 1, dp[3] = 2;
    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 4] + dp[i - 2] + dp[i - 3]);
    }
    cout << dp[n] << nl;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}