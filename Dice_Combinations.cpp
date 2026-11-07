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
#define nf cout<<'\n'
#define ll long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
ll dp[N];
ll f(int n){
    if (n == 0) return 1LL;
    if (n < 0) return 0LL;
    ll& r = dp[n];
    if (r != -1) return r;
    r = (f(n - 1)%mod + f(n - 2)%mod + f(n - 3)%mod + f(n - 4)%mod + f(n - 5)%mod + f(n - 6)%mod)%mod;
    return r;
}
void solve(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << f(n) << nl;
    dbg_arr(dp, 45);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}