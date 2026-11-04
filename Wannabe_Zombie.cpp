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
    vector<int> ans(n);
    ans[0] = ans[n - 1] = (a[n - 1] - a[0] + 1) / 2;
    for (int i = 1; i < n - 1; i++) {
        int x = max((((a[i] - a[0] + 1) / 2) + (a[i + 1] - a[i] + 1) / 2), ((a[n - 1] - a[i] + 1) / 2));
        int y = max(((a[i] - a[0] + 1) / 2), ((a[n - 1] - a[i] + 1) / 2) + (a[i] - a[i - 1] + 1) / 2);
        ans[i] = min(x, y);
    }
    for (auto i : ans) cout << i << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}