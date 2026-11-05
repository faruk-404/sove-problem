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
vector<vector<ll>> d, nxt;
void floyd_init(ll n) {
    d.assign(n + 1, vector<ll>(n + 1, INF));
    nxt.assign(n + 1, vector<ll>(n + 1, -1));
    for (ll i = 1; i <= n; i++) {
        d[i][i] = 0;
        nxt[i][i] = i;
    }
}
void add_edge(ll u, ll v, ll w) {  // directed; undirected hole ulta-o call koro
    if (w < d[u][v]) {
        d[u][v] = w;
        nxt[u][v] = v;
    }
}
void floyd(ll n) {
    for (ll k = 1; k <= n; k++)
        for (ll i = 1; i <= n; i++) {
            if (d[i][k] == INF) continue;
            for (ll j = 1; j <= n; j++) {
                if (d[k][j] == INF) continue;
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
}
vector<ll> get_path(ll u, ll v) {
    vector<ll> p;
    if (nxt[u][v] == -1) return p;  // path nai
    while (u != v) {
        p.push_back(u);
        u = nxt[u][v];
    }
    p.push_back(v);
    return p;
}
void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    floyd_init(n);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);  // undirected হলে
    }
    floyd(n);
    while (q--) {
        ll u, v;
        cin >> u >> v;
        auto p = get_path(u, v);
        if (p.empty()) {
            cout << -1 << nl;
        } else {
            cout << d[u][v] << nl;
            for (ll x : p) cout << x << " ";
            cout << nl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}