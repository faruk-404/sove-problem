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
    ll n;
    cin >> n;
    ll c;
    cin >> c;
    vector<ll> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    auto ok = [&](ll mid) {
        ll C = c;
        for (int i = 0; i < n; i++) {
            if (a[i] * mid > b[i]) C -= ( (1ll*a[i] * mid)-b[i]);
            if (C < 0) return false;
        }
        return C >= 0;
    };
    ll l = 0, r = 2000000000, mid, ans = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (ok(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}