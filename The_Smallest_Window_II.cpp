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
struct Mex {
    int n;
    vector<int> cnt;
    set<int> missing;

    Mex(int n) : n(n), cnt(n + 2, 0) {
        for (int i = 0; i <= n + 1; i++) missing.insert(i);
    }
    void add(ll x) {
        if (x < 0 || x > n + 1) return;
        if (++cnt[x] == 1) missing.erase((int)x);
    }
    void remove(ll x) {
        if (x < 0 || x > n + 1 || cnt[x] == 0) return;
        if (--cnt[x] == 0) missing.insert((int)x);
    }
    int mex() { return *missing.begin(); }
};
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    for (auto& i : s) cin >> i;

    int mx = INT_MAX;
    Mex m(k + 2);
    for (int r = 0, l = 0; r < n; r++) {
        m.add(s[r]);
        while (l <= r && m.mex() > k) {
            mx = min(mx, r - l + 1);
            m.remove(s[l++]);
        }
    }
    cout << (mx == INT_MAX ? 0 : mx) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}