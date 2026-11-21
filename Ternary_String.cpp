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
    string s;
    cin >> s;
    int mx = INT_MAX;
    vector<int> a(4);
    for (int r = 0, l = 0; r < s.size(); r++) {
        a[s[r] - '0']++;
        while (a[s[l] - '0'] > 1) a[s[l++] - '0']--;
        if (a[1] && a[2] && a[3]) mx = min(mx, r - l + 1);
        dbg(a);
    }
    cout << (mx == INT_MAX ? 0 : mx) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}