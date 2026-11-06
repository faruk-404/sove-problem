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
    vector<ll> dp(n + 1, LLONG_MAX);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        string s = to_string(i);
        for (auto c : s) {
            if (c == '0') continue;
            dp[i] = min(dp[i - (int)(c - '0')] + 1, dp[i]);
        }
    }
    cout << dp[n] << nl;
    dbg(dp);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}