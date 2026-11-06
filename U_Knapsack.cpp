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
const int N = 1e3 + 5;
ll dp[N][N];
ll knap(int n, int i, int w, vector<pair<int, int>>& wv) {
    if (i >= n) return 0LL;
    ll &r = dp[i][w];
    if (r != -1) return r;
    r = knap(n, i + 1, w, wv);
    if (w >= wv[i].first) r = max(r, knap(n, i + 1, w - wv[i].first, wv) + wv[i].second);
    return r;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> wv(n);
    for (auto& [i, j] : wv) cin >> i >> j;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = -1;

    cout << knap(n, 0, k, wv) << nl;
    // dbg_grid(wv);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}