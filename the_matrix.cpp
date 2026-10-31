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

#define endl '\n'
#define nf cout << '\n'
#define int long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()
const int N = 3e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> r(n), c(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            r[i] ^= x;
            c[j] ^= x;
        }
    }
    dbg(r);
    dbg(c);
    int sum = 0;
    for (auto v : r) sum += v;
    for (auto v : c) sum += v;
    int z = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            z = max(z, r[i] & c[j]);
            dbg(z);
        }
    }
    cout << sum - 2 * z << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}