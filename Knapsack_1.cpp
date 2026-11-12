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
    int W;
    cin >> W;
    vector<ll> v(n), w(n), dp(W + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    dp[0] = 0;
    for (int j = 0; j < n; j++) {
        for (int i = W; i >= 0; i--) {
            if ((i + w[j]) > W || dp[i] == -1) continue;
            dp[i + w[j]] = max(dp[i + w[j]], (dp[i] + v[j]));
        }
    }
    // dbg(v);
    // dbg(w);
    // dbg(dp);
    cout << *max_element(all(dp)) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}