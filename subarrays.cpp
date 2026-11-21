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
    int x;
    cin >> x;
    multiset<int> st;
    int mx = 0;
    for (int i = 0; i < x; i++) st.insert(a[i]);
    cout << *--st.end() << " ";
    for (int r = x, l = 0; r < n; r++, l++) {
        st.erase(st.find(a[l]));
        st.insert(a[r]);
        mx = max(mx, (int)st.size());
        cout << *--st.end() << " ";
        dbg(st);
    }
    // cout << mx << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}