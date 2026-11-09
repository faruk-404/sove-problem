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
    int n, m;
    cin >> n >> m;
    multiset<int> ml;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ml.insert(-x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (ml.lower_bound(-x) != ml.end()) {
            cout << (abs(*ml.lower_bound(-x))) << nl;
            ml.erase(ml.lower_bound(-x));
        } else cout << -1 << nl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}