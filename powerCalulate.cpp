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

ll power(int a, int b) {
    if (b <= 0) return 1LL;
    ll aa = 1LL * power(a, b / 2);
    aa *= aa;
    if (b & 1) aa *= a;
    return aa;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << power(a, b) << nl;
    ll ans = 1;
    while (b > 0) {
        if (b & 1)ans *= a;
        a*=a;
        b >>= 1;
    }
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