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
const int N = 2e5+5;

void solve() {
    int n;
    cin >> n;

    bool dp1[n + 1];
    memset(dp1, false, sizeof(dp1));
    dp1[1] = true;
    for (int i = 1; i <= n; i++) {
        if (dp1[i] && i + 3 <= n) dp1[i + 3] = true;
        if (dp1[i] && i * 2 <= n) dp1[i * 2] = true;
    }
        if (dp1[n]) cy;
        else cn;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}