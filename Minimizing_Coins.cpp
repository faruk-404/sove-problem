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
const int N = 1e6 + 5;
ll dp[N];
ll f(int w, vector<int>& a) {
    if (w == 0) return 0LL;
    ll& r = dp[w];
    if (r != -1) return r;
    ll mm = 10000000;
    for (int i = 0; i < a.size(); i++) {
        if (w >= a[i]) mm = min(mm, f(w - a[i], a) + 1);
    }
    return r = mm;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    if (f(k, a) == 10000000) cout << -1 << nl;
    else cout << dp[k] << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}