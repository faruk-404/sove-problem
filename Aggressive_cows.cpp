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
    int c;
    cin >> c;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    sort(all(a));
    vector<int> v;
    for (int i = 1; i < n; i++) {
        v.push_back(a[i] - a[i - 1]);
    }
    dbg(v);
    auto ok = [&](ll mid) {
        int cnt = 1;
        int sum = 0;
        for (auto i:v) {
            sum += i;
            if (sum >= mid) {
                sum = 0;
                cnt++;
            }
        }
        return cnt >= c;
    };
    ll l = 0, r = 1e18, mid, ans = 0;
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
    cin >> t;
    while (t--) solve();
    return 0;
}