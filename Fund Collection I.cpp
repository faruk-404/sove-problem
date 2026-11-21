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
    set<pair<int, int>> st;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        st.insert({u, v});
    }
    if(n!=m+1){
        cn;
        return;
    }
    for (int i = 1; i < n; i++) {
        if (!st.count({i, i + 1})) {
            cn;
            return;
        }
    }
    cy;
    

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}