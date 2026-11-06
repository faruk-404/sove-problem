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
vector<vector<ll>> d;  // distance ll
void floyd_init(int n) {
    d.assign(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
}
void add_edge(int u, int v, ll w) {  // directed; undirected hole ulta-o call koro
    if (w < d[u][v])
        d[u][v] = w;

    if (w < d[v][u])
        d[v][u] = w;
}
void floyd(int n) {
    for (int k = 1; k <= n; k++) {
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
}
void cal(int n) {
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        for (auto k : {u, v}) {
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
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++)
                ans += d[i][j];
        }
        cout << ans << " ";
    }
}

void solve() {
    int n;
    cin >> n;
    floyd_init(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    floyd(n);
    cal(n);

    // dbg_grid(d);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}