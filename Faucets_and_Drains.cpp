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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        if (count(all(a[i]), 'x') == m) {
            cout << "Faucet " << i + 1 << nl;
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        if (a[0][i] == 'x') {
            cout << "Drain " << i + 1 << nl;
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}