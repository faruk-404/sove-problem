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
    int m, n;
    cin >> m >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    auto ok = [&](ll mid) {
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            int cal = (a[i][0] * a[i][1]) + a[i][2];
            cnt += ((mid / cal) * a[i][1] + min((ll)((mid % cal) / a[i][0]), (ll)a[i][1]));
        }
        return cnt >= m;
        return true;
    };
    ll l = 0, r = 1e12, mid, ans = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << nl;
    int cnt = m;
    for (int i = 0; i < n; i++) {
        int cal = (a[i][0] * a[i][1]) + a[i][2];
        cout << min(((ans / cal) * a[i][1] + min((ll)((ans % cal) / a[i][0]), (ll)a[i][1])), (ll)m) << " ";
        m -= ((ans / cal) * a[i][1] + min((ll)((ans % cal) / a[i][0]), (ll)a[i][1]));
        m = max(m, 0);
    }

    // dbg(a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}