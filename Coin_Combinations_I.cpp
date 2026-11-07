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
const int N = 3e2 + 5;
const ll mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<ll> dp(k + 1, 0);
    dp[0] = 1;
    for(auto &c:a){
        for (int i = c; i <= k;i++){
            dp[i] =(dp[i]+ dp[i - c])%mod;
        }
    }
    cout << dp[k] << nl;
    dbg(dp);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}