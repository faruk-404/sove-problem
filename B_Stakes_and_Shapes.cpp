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
    int r, s, p;
    cin >> r >> s >> p;
    int n = r + s + p;
    vector<char> rr(n, 'R');
    vector<char> ss(n, 'S');
    vector<char> pp(n, 'P');

    if (r >= s && r >= p) {
        for (auto i : pp) cout << i;
    } else if (s >= r && s >= p) {
        for (auto i : rr) cout << i;
    } else
        for (auto i : ss) cout << i;
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}