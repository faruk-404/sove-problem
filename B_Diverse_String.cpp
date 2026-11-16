#include <bits/stdc++.h>
using namespace std;
// #ifdef LOCAL
// #include "debug.h"
// #else
// #define dbg(...)
// #define dbg_arr(...)
// #define dbg_range(...)
// #define dbg_grid(...)
// #define dbg_time(...)
// #endif

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
    string s;
    cin >> s;
    int ze = count(all(s), '0');
    int on = n - ze;
    int x = min(k, ze);
    int y = min(k, on);

    int mx = max((x + on), (y + ze));
    auto sum = [&](int c) {
        return (1LL * c * (c + 1) / 2);
    };
    cout << sum(mx) + sum(n - mx) + 1 << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}