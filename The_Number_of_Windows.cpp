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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    while (q--) {
        ll x, cnt = 0, sum = 0;
        cin >> x;
        for (int i = 0, j = 0; i < n; i++) {
            sum += a[i];
            while (sum > x) sum -= a[j++];
            if (sum <= x) cnt += (i - j + 1);
        }
        cout << cnt << nl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}