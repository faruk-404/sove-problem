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
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()
const int N = 3e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    auto su = [&](int nn) { return (nn * (nn + 1) / 2); };
    auto sum = [&](int l, int r) { return su(r) - su(l - 1); };
    auto ok = [&](int mid) { return sum(mid, k + n - 1) >= sum(k, mid); };
    auto ok2 = [&](int mid) { return sum(mid, k + n - 1) <= sum(k, mid); };

    int l = k, r = k + n - 1, mid, ans1 = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (ok(mid)) {
            ans1 = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    l = k, r = k + n - 1, mid;
    int ans2 = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (ok2(mid)) {
            ans2 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    int cnt1 = abs(sum(k, ans1) - sum(ans1 + 1, k + n - 1));
    int cnt2 = abs(sum(k, ans2) - sum(ans2 + 1, k + n - 1));
    cout << min(cnt1, cnt2) << nl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}