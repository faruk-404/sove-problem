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
    int n,k;
    cin >> n>>k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    set<int> st;
    int mx = 0;
    for (int r = 0, l = 0; r < n; r++) {
        while (st.size()>k) st.erase(a[l++]);
        st.insert(a[r]);
        mx = max(mx, (int)st.size());
        dbg(st);
    }
    cout << mx << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}