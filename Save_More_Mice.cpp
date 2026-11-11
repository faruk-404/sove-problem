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
    int n, c;
    cin >> n >> c;
    vector<ll> a(c);
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        a[i] = n - x;
    }
    dbg(a);
    sort(all(a));
    for (int i = 1; i < c; i++) {
        a[i] = a[i] + a[i - 1];
    }
    dbg(a);
    sort(all(a));
    cout << lower_bound(a.begin(), a.end(), (n)) - a.begin() << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}