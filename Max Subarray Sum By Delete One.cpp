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
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    int it = *max_element(all(a));

    if (it < 1) {
        cout << it << nl;
        return;
    }
    vector<ll> dp_pre(n + 1), dp_suff(n + 1);
    dp_pre[0] = max(0, a[0]);
    dp_suff[n - 1] = max(0, a[n - 1]);
    for (int i = 1, j = n - 2; i < n; i++, j--) {
        dp_pre[i] = ((dp_pre[i - 1] + a[i] < 0) ? 0 : dp_pre[i - 1] + a[i]);
        dp_suff[j] = ((dp_suff[j + 1] + a[j] < 0) ? 0 : dp_suff[j + 1] + a[j]);
    }
    ll mx = it;
    if (n >= 2) {
        mx = max({mx, dp_suff[0], dp_suff[1], dp_pre[n - 1], dp_pre[n - 2]});
    }
    for (int i = 0; i < n - 2; i++) {
        mx = max(mx, dp_pre[i] + dp_suff[i + 2]);
    }

    // dbg(dp_pre);
    // dbg(dp_suff);
    cout << mx << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}