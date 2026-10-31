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

struct DSU {
    ll c;
    vector<ll> par, rnk, siz, mm, mx;
    DSU(ll n) : par(n + 1), rnk(n + 1), siz(n + 1, 1), mm(n + 1), mx(n + 1) {
        c = n;
        for (ll i = 1; i <= n; i++) par[i] = i, mm[i] = i, mx[i] = i;
    }
    ll find(ll i) {
        if (i == par[i]) return i;
        return par[i] = find(par[i]);
    }

    ll mn(ll i)

    bool same(ll u, ll v) {
        return find(u) == find(v);
    }
    ll getsize(ll u) {
        return siz[find(u)];
    }
    ll cnt() {
        return c;
    }
    void merge(ll u, ll v) {
        u = find(u), v = find(v);
        if (u == v) return;
        else c--;
        if (rnk[u] > rnk[v]) swap(u, v);
        else if (rnk[u] == rnk[v]) rnk[v]++;
        par[u] = v;
        siz[v] += siz[u];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU d(n);
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s == "union") {
            int u, v;
            cin >> u >> v;
            d.merge(u, v);
        } else {
            int u;
            cin >> u;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}