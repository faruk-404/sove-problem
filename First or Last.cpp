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
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    while (q--) {
        int x, y;
        cin >> x >> y;
        auto it1 = lower_bound(all(a), x);
        auto it2 = upper_bound(all(a), y);
        if (*it1 == x) {
            cout << it1 - a.begin() + 1 << " ";
        } else cout << -1 << " ";
        if (it2 == a.begin() || *--it2 != y) cout << -1 << nl;
        else cout << it2 - a.begin() + 1 << nl;
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