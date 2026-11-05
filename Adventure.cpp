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
const int N = 3e3 + 5;


int dp[N][N];
int n;
int adv(int i, int W, vector<int>& v, vector<int>& w) {
    if (i >= n) return 0;
    int& r = dp[i][W];
    if (r != -1) return r;
    r = adv(i + 1, W, v, w);
    if (W >= w[i]) {
        int nibo = adv(i + 1, W - w[i], v, w) + v[i];
        r=max(r,nibo);
    }
    return r;
}
void solve() {
    int k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) dp[i][j] = -1;
    }
    dp[0][0]=0;
    vector<int> v(n);
    vector<int> w(n);
    for (int& i : w) cin >> i;
    for (auto& i : v) cin >> i;
    cout << adv(0, k, v, w) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}