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
    vector<int> a(n + 2, 0); 
    for (int i = 1; i <= n; i++) cin >> a[i];
   vector<int> m(n + 2, 0), suf(n + 3, 0);
    for (int i = n; i >= 1; i--) {
        int r = min(n, i + k);
        int sum = suf[i + 1] - suf[r + 1];
        m[i] = (a[i] % 2 + sum + 2) % 2;
        suf[i] = (m[i] + suf[i + 1]) % 2;
    }
    
    if (suf[1] == 1) cout << "Alice" << nl;
    else cout << "Bob" << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}