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
#define all(v) v.rbegin(), v.rend()
const int N = 3e5 + 5;

map<pair<int, ll>, ll> dp;
ll fn(int i, ll w, vector<ll>& a) {
    if (i < 0) return 0;
    if (dp.count({i, w}))
        return dp[{i, w}];
    ll aa = fn(i - 1, w, a);
    if (w >= a[i]) {
        aa = max(aa, fn(i - 1, w - a[i], a) + a[i]);
    }
    return dp[{i, w}] = aa;
}
void solve() {
    // // dbg_grid(dp);
    // dp.clear();
    // // dbg_grid(dp);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    for (auto& i : a) i = (1 << i);
    sort(all(a));

    ll x = 0, y = 0;
    for (int i = 0; i < n;i++){
        if (x < y) x += a[i];
        else y += a[i];
    }
    cout << x * y << nl;
    // ll sum = accumulate(all(a), 0LL);
    // ll W = sum / 2;
    // ll x = fn(n - 1, W, a);
    // cout << x * (sum - x) << nl;

    // vector<ll> dp(W + 1, 0);

    // for (int i = 0; i < n; i++) {
    //     for (int w = W; w >= a[i]; w--) {
    //         dp[w] = max(dp[w], dp[w - a[i]] + a[i]);
    //     }
    // }

    // dbg(dp[W]);

   
    // cout << dp[W]*(sum-dp[W])<< nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}