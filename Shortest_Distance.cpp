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

const ll INF = 1e18;
vector<vector<ll>> d;
void floyd_init(int n) {
    d.assign(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
}
void add_edge(int u, int v, ll w) {
    if (w < d[u][v]) {
        d[u][v] = w;
    }
}
void floyd(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++) {
            if (d[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (d[k][j] == INF) continue;
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
}

void solve() {
    int n, m;
    cin >> n >> m;
    floyd_init(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        add_edge(a, b, w);
    }
    floyd(n);
    int  q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        if (d[u][v] == INF) cout << -1 << nl;
        else cout << d[u][v] << nl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}