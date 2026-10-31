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
    int ans = 0;
    for (int i = 1; i < n; i++)
        if (a[i - 1] == a[i]) ans++;
    bool cnt1 = false, cnt2 = false;
    int c = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] + 1 == a[i - 1]) {
            c = i;
            cnt1 = true;
            break;
        }
    }
    for (int i = n - 2; i >= c; i--) {
        if (a[i] + 1 == a[i + 1]) {
            cnt2 = true;
            break;
        }
    }
    cout << ans + cnt1 + cnt2 << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}