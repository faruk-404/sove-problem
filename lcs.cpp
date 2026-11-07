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
int dp[100][100];
int f(int l, int r, string& s, string& t) {
    if (l < 0 || r < 0) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;

    if (s[l] == t[r]) dp[l][r]= f(l - 1, r - 1, s, t) + 1;
    dp[l][r] = max(dp[l][r], f(l - 1, r, s, t));
    dp[l][r] = max(dp[l][r], f(l, r - 1, s, t));
    return dp[l][r];
}
void solve() {
    memset(dp, -1, sizeof(dp));
    string s, t;
    cin >> s >> t;
    cout << f(s.size()-1, t.size()-1, s, t) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}