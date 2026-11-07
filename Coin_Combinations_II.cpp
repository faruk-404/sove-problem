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
const int MX = 1e6 + 5;
const ll mod = 1e9 + 7;
int n, k;
vector<int> a;
vector<vector<int>> dp;  // dp[i][w]

int f(int i, int w) {
    if (w == 0) return 1;
    if (w < 0 || i == n) return 0;
    int& r = dp[i][w];
    if (r != -1) return r;
    r = (f(i + 1, w) + f(i, w - a[i])) % mod;
    return r;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (auto& c : a) cin >> c;
    dp.assign(n, vector<int>(k + 1, -1));
    cout << f(0, k) << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}