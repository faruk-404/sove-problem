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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    int c = 1;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) c++;
        else {
            cnt += (c / 3);
            c = 1;
        }
        // dbg(cnt, s, c);
    }
    cnt += (c / 3);
    cout << cnt << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}