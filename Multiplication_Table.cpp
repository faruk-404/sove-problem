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
    cout << n << nl;
    vector<pair<int,pair<int,int>>> a;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a.push_back({i * j,{i,j}});
        }
    }
    sort(all(a));

    dbg_grid(a);
    dbg(a[(n * n / 2) - 1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}