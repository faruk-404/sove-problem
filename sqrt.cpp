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
    double n;
    cin >> n;
    if (n < 0) {
        cout << "Accept positive number only!\n";
        return;
    }
    auto ok = [&](double mid) {
        return (mid * mid <= n);
    };
    double l = 0,
           r = 1e9;
    for (ll it = 0; it < 100; it++) {
        double mid = (l + r) / 2;
        if (ok(mid)) l = mid;
        else r = mid;
    }
    cout << "Square root of " << setprecision(6) << fixed << n << " is " << l << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}