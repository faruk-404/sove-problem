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

ll dp[N];
ll fn(int i, vector<int>& a) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    ll aa = 1e15;
    if (i > 0) aa = min(aa, fn(i - 1, a) + abs(a[i] - a[i - 1]));
    if (i > 1) aa = min(aa, fn(i - 2, a) + abs(a[i] - a[i - 2]));
    return dp[i]=aa;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    memset(dp, -1, sizeof(dp));
    cout << fn(n - 1, a) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}