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
    int n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    mp[0] = 1;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        ans += mp[sum - k];
        mp[sum]++;
    }
    // dbg_grid(mp);
    cout << ans << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}