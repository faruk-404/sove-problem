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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    auto ok = [&](ll mid) {
        int cnt = 1;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + a[i] > mid) {
                cnt++;
                sum = 0;
            }
            sum += a[i];
        }
        return (cnt <= k);
    };
    ll l = 1, r = 1e17, mid, ans = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << max(ans,(ll)*max_element(all(a))) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}