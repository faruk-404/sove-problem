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
    vector<ll> d(n, INT_MAX), dd(n, INT_MAX);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) d[i] = i - 1;
        else d[i] = d[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != a[i + 1]) dd[i] = i + 1;
        else dd[i] = dd[i + 1];
    }
    for (int i = 0; i < n; i++) {
        cout << min(abs(dd[i] - i), abs(d[i] - i)) << ' ';
    }
    // dbg(d);
    // dbg(dd);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}